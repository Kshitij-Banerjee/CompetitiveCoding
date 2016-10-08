//
//  main.cpp
//  Treebo-MC
//
//  Created by Kshitij Banerjee on 24/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <regex>

using namespace std;
typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// ------------- HELPERS ------------------
std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    
    return (*p == 0) ;
}

inline bool isURL( const string* s ) {
    std::regex regex (
                          R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)",
                          std::regex::extended
                          );
    
    std::regex url_regex(".*www\\..*\\..*");
    std::smatch url_match_result;
    
    if (std::regex_match(*s, url_match_result, url_regex))
        return true;
    
    return false;
};

inline bool isSet( const string* s ) {
    size_t length = s->length();
    if( (s->at(0) == '[')  && (s->at(length-1) == ']'))
        return true;
    
    return false;
};


// -------------------- Strategies ------------------
class EvalStrategy {
protected:
    string _str;
public:
    string virtual eval() = 0;
    EvalStrategy( string in ) : _str( in ) {};
};

// ------------- Primitives -------------------------
class NumberStrategy : public EvalStrategy {
    
public:
    string eval() {
        return _str;
    }
    
    NumberStrategy(string inp) : EvalStrategy(inp) {};
};


class HttpUriStrategy : public EvalStrategy {
public:
    string eval() {
        stringstream ss;
        ss << "curl -I  ";
        ss << _str;
        string s =  exec(ss.str().c_str());
        vector<string> sss = split(s, ' ');
        return sss[1];
    }
    
    HttpUriStrategy( string inp ) : EvalStrategy(inp) {};
};

class SetStrategy : public EvalStrategy {
public:
    string eval() {
        return _str;
    }
    SetStrategy(string inp) : EvalStrategy(inp) {};
};

class Operator {
public:
    string virtual operate(EvalStrategy* s1, EvalStrategy* s2) = 0;
};

// --------------- Operator ----------------------

class AddOperator : public Operator {
    
public:
    string operate(NumberStrategy* s1, NumberStrategy* s2) {
        
        int sum = atoi(s1->eval().c_str()) + atoi(s2->eval().c_str());
        stringstream ss;
        ss << sum;
        return ss.str();
    }
    string operate(NumberStrategy* s1, HttpUriStrategy* s2){
        
        int sum = atoi(s1->eval().c_str()) + atoi(s2->eval().c_str());
        stringstream ss;
        ss << sum;
        return ss.str();
    }
    
    string operate(SetStrategy* s1, SetStrategy* s2){
        string ss1 = s1->eval();
        string ss2 = s2->eval();
        
        string sss1 = ss1.substr(1, ss1.size()-2);
        string sss2 = ss2.substr(1, ss2.size()-2);
        vector<string> input1 = split(sss1,'|');
        vector<string> input2 = split(sss2,'|');
        
        set<int> result;
        for( auto i : input1 ){
            result.insert( atoi(i.c_str()) );
        }
        for( auto i : input2 ){
            result.insert( atoi(i.c_str()) );
        }
        stringstream ss;
        
        ss << '[';
        
        for( auto i : result )
            ss << to_string(i) << ",";
        
        stringstream stream;
        string out = ss.str();
        stream << out.substr(0, out.length()-1);
        stream << ']';
        return stream.str();
    }
    
    string operate(EvalStrategy* s1, EvalStrategy* s2){
        
        if( NumberStrategy* numS = dynamic_cast<NumberStrategy*>(s1) ){
            if( NumberStrategy* numS2 = dynamic_cast<NumberStrategy*>(s2) ){
                return operate( numS, numS2);
            } else if( HttpUriStrategy* httpS = dynamic_cast<HttpUriStrategy*>(s2)){
                return operate( numS, httpS);
            }
        } else if( SetStrategy* setS = dynamic_cast<SetStrategy*>(s1) ){
            if( SetStrategy* setS2 = dynamic_cast<SetStrategy*>(s2) ){
                return operate( setS, setS2 );
            }
        } else if( HttpUriStrategy* httpS = dynamic_cast<HttpUriStrategy*>(s1)){
            if( NumberStrategy* numS = dynamic_cast<NumberStrategy*>(s2)){
                return operate( numS, httpS );
            }
        }
        else{
            throw std::invalid_argument( "Invalid Strategy" );
        }
        return "BAD_RESPONSE";
    }
};


// ------------------ Composite Strategy ------------------

class CompositeEvalStrategy : public EvalStrategy {
    
    EvalStrategy* _strat1;
    EvalStrategy* _strat2;
    Operator* _op;
public:
    CompositeEvalStrategy(EvalStrategy* s1, EvalStrategy* s2, Operator* op) : _strat1(s1), _strat2(s2), _op(op), EvalStrategy("") {};
    
    string eval() {
        return _op->operate(_strat1, _strat2);
    }
};


// ------------- Factory ---------------------

class StratFactory {
public:
    static EvalStrategy* get_strategy(string inp) {
        
        size_t pos = inp.find('+');
        if( pos != string::npos ){
            EvalStrategy* s1 = get_strategy(string(inp.begin(), inp.begin()+pos));
            EvalStrategy* s2 = get_strategy(string(inp.begin()+pos+1, inp.end()));
            AddOperator* op = new AddOperator();
            return new CompositeEvalStrategy(s1, s2, op);
        } else if (isInteger(inp)){
            return new NumberStrategy(inp);
        } else if(isSet(&inp)) {
            return new SetStrategy(inp);
        } else if (isURL(&inp)) {
            return new HttpUriStrategy(inp);
        } else{
            throw std::invalid_argument( "Unknown Strategy" );
        }
    
        return NULL;
    }
};


int main(int argc, const char * argv[]) {
    
    string input;
    cin >> input;
    
    for( int i = 0; i < input.size(); i++ ){
        if( input[i] == '[' ){
            while( input[i] != ']'){ if( input[i] == ',') input[i] = '|'; i++; }
        }
    }
    vector<string> csv = split(input, ',');
    
    vector<EvalStrategy*> strategies;
    for( auto str : csv ) {
        strategies.push_back(StratFactory::get_strategy(str));
    }
    
    vector<string> output;
    for( auto strat : strategies)
        output.push_back(strat->eval());
    
    cout << "-----------------OUTPUT----------------" << endl;
    for( auto out : output ) {
        cout << out << endl;
    }
    
    return 0;
}
