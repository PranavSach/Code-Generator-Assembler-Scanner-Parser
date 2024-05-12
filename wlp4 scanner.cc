#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include  <stdio.h>
#include <deque>
//// The dfa.h header defines a string constant containing a DFA file:
// std::string DFAstring = ...
#include "dfaWips.h"

//// Function that takes a DFA file (passed as a stream) and prints information about it.
void DFAprint(std::istream &in);

//// These helper functions are defined at the bottom of the file:
// Check if a string is a single character.
bool isChar(std::string s);
// Check if a string represents a character range.
bool isRange(std::string s);
// Remove leading and trailing whitespace from a string, and
// squish intermediate whitespace sequences down to one space each.
std::string squish(std::string s);
// Convert hex digit character to corresponding number.
int hexToNum(char c);
// Convert number to corresponding hex digit character.
char numToHex(int d);
// Replace all escape sequences in a string with corresponding characters.
std::string escape(std::string s);
// Convert non-printing characters or spaces in a string into escape sequences.
std::string unescape(std::string s);

const std::string STATES      = ".STATES";
const std::string TRANSITIONS = ".TRANSITIONS";
const std::string INPUT       = ".INPUT";





DFA::DFA(std::istream &in) {
  std::string s;
  // Skip blank lines at the start of the file
  while(true) {
    if (!(std::getline(in, s))) {
      throw std::runtime_error
        ("Expected " + STATES + ", but found end of input.");
    }
    s = squish(s);
    if (s == STATES) {
      break;
    }
    if (!s.empty()) {
      throw std::runtime_error
        ("Expected " + STATES + ", but found: " + s);
    }
  }
  // Print states
  bool initial = true;
  while(true) {
    if (!(in >> s)) {
      throw std::runtime_error
        ("Unexpected end of input while reading state set: " 
         + TRANSITIONS + "not found.");
    }
    if (s == TRANSITIONS) {
      break;
    } 
    // Process an individual state
    bool accepting = false;
    if (s.back() == '!' && s.length() > 1) {
      accepting = true;
      s.pop_back();
      ac_states.emplace_back(s);
    }
    states.emplace_back(s);
    /*std::cout << s 
              << (initial   ? " (initial)"   : "") 
              << (accepting ? " (accepting)" : "") << '\n';*/
    // Only the first state is marked as initial
    initial = false;
  }
  // Print transitions
  std::getline(in, s); // Skip .TRANSITIONS header
  while(true) {
    if (!(std::getline(in, s))) {
      // We reached the end of the file
      break;
    }
    s = squish(s);
    if (s == INPUT) {
      break;
    } 
    // Split the line into parts
    std::string lineStr = s;
    std::stringstream line(lineStr);
    std::vector<std::string> lineVec;
    while(line >> s) {
      lineVec.push_back(s);
    }
    if(lineVec.empty()) {
      // Skip blank lines
      continue;
    }
    if (lineVec.size() < 3) {
      throw std::runtime_error
        ("Incomplete transition line: " + lineStr);
    }
    // Extract state information from the line
    std::string fromState = lineVec.front();
    std::string toState = lineVec.back();
    // Extract character and range information from the line
    std::vector<char> charVec;
    for(int i = 1; i < lineVec.size()-1; ++i) {
      std::string charOrRange = escape(lineVec[i]);
      if (isChar(charOrRange)) {
        char c = charOrRange[0];
        if (c < 0 || c > 127) {
          throw std::runtime_error
            ("Invalid (non-ASCII) character in transition line: " + lineStr + "\n"
             + "Character " + unescape(std::string(1,c)) + " is outside ASCII range");
        }
        charVec.push_back(c);
        transition[std::make_pair(fromState, c)] = toState;
      } else if (isRange(charOrRange)) {
        for(char c = charOrRange[0]; charOrRange[0] <= c && c <= charOrRange[2]; ++c) {
          transition[std::make_pair(fromState, c)] = toState;
          charVec.push_back(c);
        }
      } else {
        throw std::runtime_error
          ("Expected character or range, but found "
           + charOrRange + " in transition line: " + lineStr);
      }
    }
    // Print a representation of the transition line
    /*std::cout << fromState << ' ';
    for ( char c : charVec ) {
      std::cout << unescape(std::string(1,c)) << ' ';
    }
    std::cout << toState << '\n';*/
  }
   /*for (const auto& entry : transition) {
        const std::pair<std::string, char>& key = entry.first;
        const std::string& value = entry.second;

        std::cout << "Key: (" << key.first << ", " << key.second << "), Value: " << value << std::endl;
    }
    for (size_t i = 0; i < states.size(); ++i) {
        std::cout << states[i] << std::endl;
    }
*/
  // We ignore .INPUT sections, so we're done
}

//// Helper functions

bool isChar(std::string s) {
  return s.length() == 1;
}

bool isRange(std::string s) {
  return s.length() == 3 && s[1] == '-';
}

std::string squish(std::string s) {
  std::stringstream ss(s);
  std::string token;
  std::string result;
  std::string space = "";
  while(ss >> token) {
    result += space;
    result += token;
    space = " ";
  }
  return result;
}

int hexToNum(char c) {
  if ('0' <= c && c <= '9') {
    return c - '0';
  } else if ('a' <= c && c <= 'f') {
    return 10 + (c - 'a');
  } else if ('A' <= c && c <= 'F') {
    return 10 + (c - 'A');
  }
  // This should never happen....
  throw std::runtime_error("Invalid hex digit!");
}

char numToHex(int d) {
  return (d < 10 ? d + '0' : d - 10 + 'A');
}

std::string escape(std::string s) {
  std::string p;
  for(int i=0; i<s.length(); ++i) {
    if (s[i] == '\\' && i+1 < s.length()) {
      char c = s[i+1]; 
      i = i+1;
      if (c == 's') {
        p += ' ';            
      } else
      if (c == 'n') {
        p += '\n';            
      } else
      if (c == 'r') {
        p += '\r';            
      } else
      if (c == 't') {
        p += '\t';            
      } else
      if (c == 'x') {
        if(i+2 < s.length() && isxdigit(s[i+1]) && isxdigit(s[i+2])) {
          if (hexToNum(s[i+1]) > 8) {
            throw std::runtime_error(
                "Invalid escape sequence \\x"
                + std::string(1, s[i+1])
                + std::string(1, s[i+2])
                +": not in ASCII range (0x00 to 0x7F)");
          }
          char code = hexToNum(s[i+1])*16 + hexToNum(s[i+2]);
          p += code;
          i = i+2;
        } else {
          p += c;
        }
      } else
      if (isgraph(c)) {
        p += c;            
      } else {
        p += s[i];
      }
    } else {
       p += s[i];
    }
  }  
  return p;
}

std::string unescape(std::string s) {
  std::string p;
  for(int i=0; i<s.length(); ++i) {
    char c = s[i];
    if (c == ' ') {
      p += "\\s";
    } else
    if (c == '\n') {
      p += "\\n";
    } else
    if (c == '\r') {
      p += "\\r";
    } else
    if (c == '\t') {
      p += "\\t";
    } else
    if (!isgraph(c)) {
      std::string hex = "\\x";
      p += hex + numToHex((unsigned char)c/16) + numToHex((unsigned char)c%16);
    } else {
      p += c;
    }
  }
  return p;
}


string DFA::get_next(string fromstate, char cc){
   pair<string, char> lookup = make_pair(fromstate, cc);
  auto pos = transition.find(lookup);
  if (pos != transition.end()){
    return pos->second;
  }
  else{
    return "Error_no_state";
  }
}


//helpers for SMM
bool is_ac(string p, vector<string> v){
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == p) {
      return true;
    }
  }
  return false;
}


std::ostream &operator<<(std::ostream &out, Token &t){
        if (t.lexeme != ""){
            out << t.kind << " " << t.lexeme; 
        }
        else{
            out << t.kind;
        }
        return out;
    }



void SMM(DFA &d){
  char x;
  deque<Token> output;
  string p =  d.states.front();
  string t = "";
  x = getchar();
  while (x != EOF){
    //cout << p << endl;
    char a = x;
    if (d.get_next(p,a) != "Error_no_state"){
      t += a;
      //x.erase(0);
      x = getchar();
      p = d.get_next(p,a);
      //cout << p << endl;
      
    }
    else {
      if (is_ac(p, d.ac_states) == true){
        if (p == "?WHITESPACE" || p == "?COMMENT"){
          p = d.states.front();
          t = "";
        }
        else if (p == "ID"){
            if (t == "int"){
                p = "INT";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";
            }
            else if (t == "wain"){
                p = "WAIN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "if"){
                p = "IF";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "else"){
                p = "ELSE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "while"){
                p = "WHILE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "println"){
                p = "PRINTLN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "return"){
                p = "RETURN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "new"){
                p = "NEW";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "delete"){
                p = "DELETE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "NULL"){
                p = "NULL";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else{
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";
            }
          
        }
        else if (p == "NUM"){
          if (t[0] == '0' && t.length() > 1){
            cerr << "ERROR";
            throw std::runtime_error("leading zeros");
            }
            else{
          long num = stol(t);
          //cout << num << endl;
          if (num > 2147483647){
            cerr << "ERROR";
            throw std::runtime_error("Num limit");
          }
          else{
            Token tok(p, t);
            output.emplace_back(tok);
            p = d.states.front();
            t = "";
          }
            }
        }
        else if (p == "ZERO"){
          p = "NUM";
          Token tok(p, t);
          output.emplace_back(tok);
          p = d.states.front();
          t = "";
        }
        else{
          Token tok(p, t);
          output.emplace_back(tok);
          p = d.states.front();
          t = "";
        }
      }
      else{
        cerr << "ERROR";
        throw std::runtime_error("Invalid input");
      }
    }
  }
  if (is_ac(p, d.ac_states) == true){
    if (p == "?WHITESPACE" || p == "?COMMENT"){
          p = d.states.front();
          t = "";
        }
        else if (p == "ID"){
            if (t == "int"){
                p = "INT";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";
            }
            else if (t == "wain"){
                p = "WAIN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "if"){
                p = "IF";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "else"){
                p = "ELSE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "while"){
                p = "WHILE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "println"){
                p = "PRINTLN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "return"){
                p = "RETURN";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "new"){
                p = "NEW";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "delete"){
                p = "DELETE";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else if (t == "NULL"){
                p = "NULL";
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";

            }
            else{
                Token tok(p, t);
                output.emplace_back(tok);
                p = d.states.front();
                t = "";
            }
          
        }
        else if (p == "NUM"){
            if (t[0] == '0' && t.length() > 1){
            cerr << "ERROR";
            throw std::runtime_error("leading zeros");
            }
            else{
          long num = stol(t);
          //cout << num << endl;
          if (num > 2147483647){
            cerr << "ERROR";
            throw std::runtime_error("Num limit");
          }
          else{
            Token tok(p, t);
            output.emplace_back(tok);
            p = d.states.front();
            t = "";
          }
            }
        }
        else if (p == "ZERO"){
          p = "NUM";
          Token tok(p, t);
          output.emplace_back(tok);
          p = d.states.front();
          t = "";
        }
        else{
          Token tok(p, t);
          output.emplace_back(tok);
          p = d.states.front();
          t = "";
        }
    for (int i = 0; i < output.size(); i++) {
      /*if (i == 0){
        cout << output[i];
      }
      else{*/
       
        cout << output[i];
        cout << endl;
      //}
      
    }
  }
  else{
    cerr << "ERROR";
    throw std::runtime_error("Invalid input");
  }
}



int main() {
  try {
    std::stringstream s(DFAstring);
    DFA dfa(s);
    SMM(dfa);
  } catch(std::runtime_error &e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 1;
  }
  return 0;
}


