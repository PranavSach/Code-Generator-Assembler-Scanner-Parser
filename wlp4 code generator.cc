#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include  <stdio.h>
#include <deque>
#include <map>
using namespace std;

const std::string WLP4_CFG = R"END(.CFG
start BOF procedures EOF
procedures procedure procedures
procedures main
procedure INT ID LPAREN params RPAREN LBRACE dcls statements RETURN expr SEMI RBRACE
main INT WAIN LPAREN dcl COMMA dcl RPAREN LBRACE dcls statements RETURN expr SEMI RBRACE
params .EMPTY
params paramlist
paramlist dcl
paramlist dcl COMMA paramlist
type INT
type INT STAR
dcls .EMPTY
dcls dcls dcl BECOMES NUM SEMI
dcls dcls dcl BECOMES NULL SEMI
dcl type ID
statements .EMPTY
statements statements statement
statement lvalue BECOMES expr SEMI
statement IF LPAREN test RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE
statement WHILE LPAREN test RPAREN LBRACE statements RBRACE
statement PRINTLN LPAREN expr RPAREN SEMI
statement DELETE LBRACK RBRACK expr SEMI
test expr EQ expr
test expr NE expr
test expr LT expr
test expr LE expr
test expr GE expr
test expr GT expr
expr term
expr expr PLUS term
expr expr MINUS term
term factor
term term STAR factor
term term SLASH factor
term term PCT factor
factor ID
factor NUM
factor NULL
factor LPAREN expr RPAREN
factor AMP lvalue
factor STAR factor
factor NEW INT LBRACK expr RBRACK
factor ID LPAREN RPAREN
factor ID LPAREN arglist RPAREN
arglist expr
arglist expr COMMA arglist
lvalue ID
lvalue STAR factor
lvalue LPAREN lvalue RPAREN
)END";

const std::string WLP4_TRANSITIONS = R"END(.TRANSITIONS
0 BOF 45
1 AMP 35
1 ID 13
1 LPAREN 1
1 NEW 30
1 NULL 33
1 NUM 10
1 STAR 6
1 expr 86
1 factor 83
1 term 51
100 EQ 40
100 GE 37
100 GT 46
100 LE 34
100 LT 27
100 MINUS 3
100 NE 14
100 PLUS 74
102 AMP 35
102 ID 13
102 LPAREN 1
102 NEW 30
102 NULL 33
102 NUM 10
102 STAR 6
102 expr 11
102 factor 83
102 term 51
103 AMP 35
103 ID 13
103 LPAREN 1
103 NEW 30
103 NULL 33
103 NUM 10
103 RPAREN 44
103 STAR 6
103 arglist 125
103 expr 38
103 factor 83
103 term 51
104 AMP 35
104 ID 13
104 LPAREN 1
104 NEW 30
104 NULL 33
104 NUM 10
104 STAR 6
104 expr 72
104 factor 83
104 term 51
105 AMP 35
105 ID 13
105 LPAREN 1
105 NEW 30
105 NULL 33
105 NUM 10
105 STAR 6
105 factor 55
108 DELETE 57
108 ID 19
108 IF 53
108 LPAREN 4
108 PRINTLN 2
108 RBRACE 119
108 STAR 73
108 WHILE 43
108 lvalue 12
108 statement 20
109 DELETE 57
109 ID 19
109 IF 53
109 LPAREN 4
109 PRINTLN 2
109 RBRACE 120
109 STAR 73
109 WHILE 43
109 lvalue 12
109 statement 20
11 MINUS 3
11 PLUS 74
11 SEMI 23
110 DELETE 57
110 ID 19
110 IF 53
110 LPAREN 4
110 PRINTLN 2
110 RBRACE 121
110 STAR 73
110 WHILE 43
110 lvalue 12
110 statement 20
111 AMP 35
111 ID 13
111 LPAREN 1
111 NEW 30
111 NULL 33
111 NUM 10
111 STAR 6
111 factor 54
113 LBRACE 77
114 SEMI 69
115 INT 68
115 main 28
115 procedure 115
115 procedures 16
118 AMP 35
118 ID 13
118 LPAREN 1
118 NEW 30
118 NULL 33
118 NUM 10
118 STAR 6
118 arglist 65
118 expr 38
118 factor 83
118 term 51
119 ELSE 113
12 BECOMES 97
122 INT 17
122 dcl 15
122 paramlist 123
122 params 18
122 type 48
124 INT 17
124 dcl 63
124 statements 42
124 type 48
125 RPAREN 24
126 LBRACK 79
128 LPAREN 84
129 EOF 107
13 LPAREN 103
131 LPAREN 122
14 AMP 35
14 ID 13
14 LPAREN 1
14 NEW 30
14 NULL 33
14 NUM 10
14 STAR 6
14 expr 88
14 factor 83
14 term 51
15 COMMA 99
17 STAR 95
18 RPAREN 36
2 LPAREN 9
23 RBRACE 41
25 LBRACE 61
27 AMP 35
27 ID 13
27 LPAREN 1
27 NEW 30
27 NULL 33
27 NUM 10
27 STAR 6
27 expr 89
27 factor 83
27 term 51
29 DELETE 57
29 ID 19
29 IF 53
29 LPAREN 4
29 PRINTLN 2
29 RETURN 102
29 STAR 73
29 WHILE 43
29 lvalue 12
29 statement 20
3 AMP 35
3 ID 13
3 LPAREN 1
3 NEW 30
3 NULL 33
3 NUM 10
3 STAR 6
3 factor 83
3 term 60
30 INT 126
31 LBRACE 80
32 LBRACE 81
34 AMP 35
34 ID 13
34 LPAREN 1
34 NEW 30
34 NULL 33
34 NUM 10
34 STAR 6
34 expr 90
34 factor 83
34 term 51
35 ID 19
35 LPAREN 4
35 STAR 73
35 lvalue 93
36 LBRACE 5
37 AMP 35
37 ID 13
37 LPAREN 1
37 NEW 30
37 NULL 33
37 NUM 10
37 STAR 6
37 expr 91
37 factor 83
37 term 51
38 COMMA 118
38 MINUS 3
38 PLUS 74
39 RBRACE 106
4 ID 19
4 LPAREN 4
4 STAR 73
4 lvalue 94
40 AMP 35
40 ID 13
40 LPAREN 1
40 NEW 30
40 NULL 33
40 NUM 10
40 STAR 6
40 expr 87
40 factor 83
40 term 51
42 DELETE 57
42 ID 19
42 IF 53
42 LPAREN 4
42 PRINTLN 2
42 RETURN 52
42 STAR 73
42 WHILE 43
42 lvalue 12
42 statement 20
43 LPAREN 8
45 INT 68
45 main 28
45 procedure 115
45 procedures 129
46 AMP 35
46 ID 13
46 LPAREN 1
46 NEW 30
46 NULL 33
46 NUM 10
46 STAR 6
46 expr 92
46 factor 83
46 term 51
48 ID 101
49 RPAREN 31
5 dcls 98
50 RPAREN 32
51 PCT 67
51 SLASH 105
51 STAR 111
52 AMP 35
52 ID 13
52 LPAREN 1
52 NEW 30
52 NULL 33
52 NUM 10
52 STAR 6
52 expr 64
52 factor 83
52 term 51
53 LPAREN 7
57 LBRACK 78
58 SEMI 117
59 PCT 67
59 SLASH 105
59 STAR 111
6 AMP 35
6 ID 13
6 LPAREN 1
6 NEW 30
6 NULL 33
6 NUM 10
6 STAR 6
6 factor 26
60 PCT 67
60 SLASH 105
60 STAR 111
61 dcls 124
62 NULL 58
62 NUM 82
63 BECOMES 62
64 MINUS 3
64 PLUS 74
64 SEMI 39
67 AMP 35
67 ID 13
67 LPAREN 1
67 NEW 30
67 NULL 33
67 NUM 10
67 STAR 6
67 factor 56
68 ID 131
68 WAIN 128
7 AMP 35
7 ID 13
7 LPAREN 1
7 NEW 30
7 NULL 33
7 NUM 10
7 STAR 6
7 expr 100
7 factor 83
7 term 51
7 test 49
70 MINUS 3
70 PLUS 74
70 SEMI 22
71 MINUS 3
71 PLUS 74
71 RPAREN 114
72 MINUS 3
72 PLUS 74
72 SEMI 21
73 AMP 35
73 ID 13
73 LPAREN 1
73 NEW 30
73 NULL 33
73 NUM 10
73 STAR 6
73 factor 66
74 AMP 35
74 ID 13
74 LPAREN 1
74 NEW 30
74 NULL 33
74 NUM 10
74 STAR 6
74 factor 83
74 term 59
75 COMMA 96
76 RPAREN 25
77 statements 110
78 RBRACK 104
79 AMP 35
79 ID 13
79 LPAREN 1
79 NEW 30
79 NULL 33
79 NUM 10
79 STAR 6
79 expr 85
79 factor 83
79 term 51
8 AMP 35
8 ID 13
8 LPAREN 1
8 NEW 30
8 NULL 33
8 NUM 10
8 STAR 6
8 expr 100
8 factor 83
8 term 51
8 test 50
80 statements 108
81 statements 109
82 SEMI 116
84 INT 17
84 dcl 75
84 type 48
85 MINUS 3
85 PLUS 74
85 RBRACK 47
86 MINUS 3
86 PLUS 74
86 RPAREN 112
87 MINUS 3
87 PLUS 74
88 MINUS 3
88 PLUS 74
89 MINUS 3
89 PLUS 74
9 AMP 35
9 ID 13
9 LPAREN 1
9 NEW 30
9 NULL 33
9 NUM 10
9 STAR 6
9 expr 71
9 factor 83
9 term 51
90 MINUS 3
90 PLUS 74
91 MINUS 3
91 PLUS 74
92 MINUS 3
92 PLUS 74
94 RPAREN 130
96 INT 17
96 dcl 76
96 type 48
97 AMP 35
97 ID 13
97 LPAREN 1
97 NEW 30
97 NULL 33
97 NUM 10
97 STAR 6
97 expr 70
97 factor 83
97 term 51
98 INT 17
98 dcl 63
98 statements 29
98 type 48
99 INT 17
99 dcl 15
99 paramlist 127
99 type 48
)END";

const std::string WLP4_REDUCTIONS = R"END(.REDUCTIONS
10 36 BECOMES
10 36 COMMA
10 36 EQ
10 36 GE
10 36 GT
10 36 LE
10 36 LT
10 36 MINUS
10 36 NE
10 36 PCT
10 36 PLUS
10 36 RBRACK
10 36 RPAREN
10 36 SEMI
10 36 SLASH
10 36 STAR
101 14 BECOMES
101 14 COMMA
101 14 RPAREN
106 4 EOF
107 0 .ACCEPT
112 38 BECOMES
112 38 COMMA
112 38 EQ
112 38 GE
112 38 GT
112 38 LE
112 38 LT
112 38 MINUS
112 38 NE
112 38 PCT
112 38 PLUS
112 38 RBRACK
112 38 RPAREN
112 38 SEMI
112 38 SLASH
112 38 STAR
116 12 DELETE
116 12 ID
116 12 IF
116 12 INT
116 12 LPAREN
116 12 PRINTLN
116 12 RETURN
116 12 STAR
116 12 WHILE
117 13 DELETE
117 13 ID
117 13 IF
117 13 INT
117 13 LPAREN
117 13 PRINTLN
117 13 RETURN
117 13 STAR
117 13 WHILE
120 19 DELETE
120 19 ID
120 19 IF
120 19 LPAREN
120 19 PRINTLN
120 19 RBRACE
120 19 RETURN
120 19 STAR
120 19 WHILE
121 18 DELETE
121 18 ID
121 18 IF
121 18 LPAREN
121 18 PRINTLN
121 18 RBRACE
121 18 RETURN
121 18 STAR
121 18 WHILE
122 5 RPAREN
123 6 RPAREN
124 15 DELETE
124 15 ID
124 15 IF
124 15 LPAREN
124 15 PRINTLN
124 15 RBRACE
124 15 RETURN
124 15 STAR
124 15 WHILE
127 8 RPAREN
13 35 BECOMES
13 35 COMMA
13 35 EQ
13 35 GE
13 35 GT
13 35 LE
13 35 LT
13 35 MINUS
13 35 NE
13 35 PCT
13 35 PLUS
13 35 RBRACK
13 35 RPAREN
13 35 SEMI
13 35 SLASH
13 35 STAR
130 48 BECOMES
130 48 COMMA
130 48 EQ
130 48 GE
130 48 GT
130 48 LE
130 48 LT
130 48 MINUS
130 48 NE
130 48 PCT
130 48 PLUS
130 48 RBRACK
130 48 RPAREN
130 48 SEMI
130 48 SLASH
130 48 STAR
15 7 RPAREN
16 1 EOF
17 9 ID
19 46 BECOMES
19 46 COMMA
19 46 EQ
19 46 GE
19 46 GT
19 46 LE
19 46 LT
19 46 MINUS
19 46 NE
19 46 PCT
19 46 PLUS
19 46 RBRACK
19 46 RPAREN
19 46 SEMI
19 46 SLASH
19 46 STAR
20 16 DELETE
20 16 ID
20 16 IF
20 16 LPAREN
20 16 PRINTLN
20 16 RBRACE
20 16 RETURN
20 16 STAR
20 16 WHILE
21 21 DELETE
21 21 ID
21 21 IF
21 21 LPAREN
21 21 PRINTLN
21 21 RBRACE
21 21 RETURN
21 21 STAR
21 21 WHILE
22 17 DELETE
22 17 ID
22 17 IF
22 17 LPAREN
22 17 PRINTLN
22 17 RBRACE
22 17 RETURN
22 17 STAR
22 17 WHILE
24 43 BECOMES
24 43 COMMA
24 43 EQ
24 43 GE
24 43 GT
24 43 LE
24 43 LT
24 43 MINUS
24 43 NE
24 43 PCT
24 43 PLUS
24 43 RBRACK
24 43 RPAREN
24 43 SEMI
24 43 SLASH
24 43 STAR
26 40 BECOMES
26 40 COMMA
26 40 EQ
26 40 GE
26 40 GT
26 40 LE
26 40 LT
26 40 MINUS
26 40 NE
26 40 PCT
26 40 PLUS
26 40 RBRACK
26 40 RPAREN
26 40 SEMI
26 40 SLASH
26 40 STAR
28 2 EOF
33 37 BECOMES
33 37 COMMA
33 37 EQ
33 37 GE
33 37 GT
33 37 LE
33 37 LT
33 37 MINUS
33 37 NE
33 37 PCT
33 37 PLUS
33 37 RBRACK
33 37 RPAREN
33 37 SEMI
33 37 SLASH
33 37 STAR
38 44 RPAREN
41 3 INT
44 42 BECOMES
44 42 COMMA
44 42 EQ
44 42 GE
44 42 GT
44 42 LE
44 42 LT
44 42 MINUS
44 42 NE
44 42 PCT
44 42 PLUS
44 42 RBRACK
44 42 RPAREN
44 42 SEMI
44 42 SLASH
44 42 STAR
47 41 BECOMES
47 41 COMMA
47 41 EQ
47 41 GE
47 41 GT
47 41 LE
47 41 LT
47 41 MINUS
47 41 NE
47 41 PCT
47 41 PLUS
47 41 RBRACK
47 41 RPAREN
47 41 SEMI
47 41 SLASH
47 41 STAR
5 11 DELETE
5 11 ID
5 11 IF
5 11 INT
5 11 LPAREN
5 11 PRINTLN
5 11 RETURN
5 11 STAR
5 11 WHILE
51 28 COMMA
51 28 EQ
51 28 GE
51 28 GT
51 28 LE
51 28 LT
51 28 MINUS
51 28 NE
51 28 PLUS
51 28 RBRACK
51 28 RPAREN
51 28 SEMI
54 32 COMMA
54 32 EQ
54 32 GE
54 32 GT
54 32 LE
54 32 LT
54 32 MINUS
54 32 NE
54 32 PCT
54 32 PLUS
54 32 RBRACK
54 32 RPAREN
54 32 SEMI
54 32 SLASH
54 32 STAR
55 33 COMMA
55 33 EQ
55 33 GE
55 33 GT
55 33 LE
55 33 LT
55 33 MINUS
55 33 NE
55 33 PCT
55 33 PLUS
55 33 RBRACK
55 33 RPAREN
55 33 SEMI
55 33 SLASH
55 33 STAR
56 34 COMMA
56 34 EQ
56 34 GE
56 34 GT
56 34 LE
56 34 LT
56 34 MINUS
56 34 NE
56 34 PCT
56 34 PLUS
56 34 RBRACK
56 34 RPAREN
56 34 SEMI
56 34 SLASH
56 34 STAR
59 29 COMMA
59 29 EQ
59 29 GE
59 29 GT
59 29 LE
59 29 LT
59 29 MINUS
59 29 NE
59 29 PLUS
59 29 RBRACK
59 29 RPAREN
59 29 SEMI
60 30 COMMA
60 30 EQ
60 30 GE
60 30 GT
60 30 LE
60 30 LT
60 30 MINUS
60 30 NE
60 30 PLUS
60 30 RBRACK
60 30 RPAREN
60 30 SEMI
61 11 DELETE
61 11 ID
61 11 IF
61 11 INT
61 11 LPAREN
61 11 PRINTLN
61 11 RETURN
61 11 STAR
61 11 WHILE
65 45 RPAREN
66 47 BECOMES
66 47 COMMA
66 47 EQ
66 47 GE
66 47 GT
66 47 LE
66 47 LT
66 47 MINUS
66 47 NE
66 47 PCT
66 47 PLUS
66 47 RBRACK
66 47 RPAREN
66 47 SEMI
66 47 SLASH
66 47 STAR
69 20 DELETE
69 20 ID
69 20 IF
69 20 LPAREN
69 20 PRINTLN
69 20 RBRACE
69 20 RETURN
69 20 STAR
69 20 WHILE
77 15 DELETE
77 15 ID
77 15 IF
77 15 LPAREN
77 15 PRINTLN
77 15 RBRACE
77 15 RETURN
77 15 STAR
77 15 WHILE
80 15 DELETE
80 15 ID
80 15 IF
80 15 LPAREN
80 15 PRINTLN
80 15 RBRACE
80 15 RETURN
80 15 STAR
80 15 WHILE
81 15 DELETE
81 15 ID
81 15 IF
81 15 LPAREN
81 15 PRINTLN
81 15 RBRACE
81 15 RETURN
81 15 STAR
81 15 WHILE
83 31 COMMA
83 31 EQ
83 31 GE
83 31 GT
83 31 LE
83 31 LT
83 31 MINUS
83 31 NE
83 31 PCT
83 31 PLUS
83 31 RBRACK
83 31 RPAREN
83 31 SEMI
83 31 SLASH
83 31 STAR
87 22 RPAREN
88 23 RPAREN
89 24 RPAREN
90 25 RPAREN
91 26 RPAREN
92 27 RPAREN
93 39 BECOMES
93 39 COMMA
93 39 EQ
93 39 GE
93 39 GT
93 39 LE
93 39 LT
93 39 MINUS
93 39 NE
93 39 PCT
93 39 PLUS
93 39 RBRACK
93 39 RPAREN
93 39 SEMI
93 39 SLASH
93 39 STAR
95 10 ID
98 15 DELETE
98 15 ID
98 15 IF
98 15 LPAREN
98 15 PRINTLN
98 15 RBRACE
98 15 RETURN
98 15 STAR
98 15 WHILE
)END";

const std::string WLP4_DFA = WLP4_TRANSITIONS+WLP4_REDUCTIONS;
const std::string WLP4_COMBINED = WLP4_CFG+WLP4_DFA;

class Token{
    public:
    string kind;
    string lexeme;
    Token(string k){
        kind = k;
        lexeme = "";
    }
    Token(string k, string l){
        kind = k;
        lexeme = l;
    }
    Token(){
        kind = "";
        lexeme = "";
    }
};




class rule{
    public:
    string LHS;
    vector<string> RHS;
    rule(string s);
    rule(){
        LHS = "";
    }
};
class CFG{
    public:
    vector<rule> rules;
    CFG(istream &in);
};

class slrDFA{
    public:
    map<pair<int, string>, int> transitions;
    map<pair<int, string>, int> reductions;
    vector<string> RHS;
    slrDFA(istream &in);
};

rule::rule(string s){
    istringstream iss(s);
    string w;
    iss >> w;
    LHS = w;
    while(iss >> w){
        if (w == ".EMPTY"){
            break;
        }
        RHS.emplace_back(w);
    }
}

CFG::CFG(istream &in){
    string s;
    getline(in, s);
    while (getline(in, s)){
        rule r(s);
        rules.emplace_back(r);
    }
}

slrDFA::slrDFA(istream &in){
    string s;
    getline(in, s);
    while (true){
        getline(in, s);
        if (s != ".REDUCTIONS"){
            istringstream iss(s);
            string state1;
            string symbol;
            string state2;
            iss >> state1;
            int st1 = stoi(state1);
            iss >> symbol;
            iss >> state2;
            int st2 = stoi(state2);
            transitions[make_pair(st1, symbol)] = st2; 
        }
        else{
            break;
        }
    }
    while (getline(in, s)){
        istringstream iss(s);
        string state1;
        string r;
        string symbol;
        iss >> state1;
        int st1 = stoi(state1);
        iss >> r;
        int ru = stoi(r);
        iss >> symbol;
        reductions[make_pair(st1, symbol)] = ru;
    }
}

/*helper*/
void Add(int d, int s, int t) { 
  std::cout << "add $" << d << ", $" << s << ", $" << t << "\n"; 
}
void Beq(int s, int t, std::string label) { 
  std::cout << "beq $" << s << ", $" << t << ", " + label + "\n"; 
}
void Jr(int s) { 
  std::cout << "jr $"  << s << "\n"; 
}
void Sub(int d, int s, int t) { 
  std::cout << "sub $" << d << ", $" << s << ", $" << t << "\n"; 
}
void Mult(int s, int t) { 
  std::cout << "mult $" << s << ", $" << t << "\n"; 
}
void Multu(int s, int t) { 
  std::cout << "multu $" << s << ", $" << t << "\n"; 
}
void Div(int s, int t) { 
  std::cout << "div $" << s << ", $" << t << "\n"; 
}
void Divu(int s, int t) { 
  std::cout << "divu $" << s << ", $" << t << "\n"; 
}
void Mfhi(int d) { 
  std::cout << "mfhi $"  << d << "\n"; 
}
void Mflo(int d) { 
  std::cout << "mflo $"  << d << "\n"; 
}
void Lis(int d) { 
  std::cout << "lis $"  << d << "\n"; 
}
void Slt(int d, int s, int t) { 
  std::cout << "slt $" << d << ", $" << s << ", $" << t << "\n"; 
}
void Sltu(int d, int s, int t) { 
  std::cout << "sltu $" << d << ", $" << s << ", $" << t << "\n"; 
}
void Jalr(int s) { 
  std::cout << "jalr $"  << s << "\n"; 
}
void Beq(int s, int t, int i) { 
  std::cout << "beq $" << s << ", $" << t << ", " << i << "\n"; 
}
void Bne(int s, int t, std::string label) { 
  std::cout << "bne $" << s << ", $" << t << ", " + label + "\n"; 
}
void Bne(int s, int t, int i) { 
  std::cout << "bne $" << s << ", $" << t << ", " << i << "\n"; 
}
void Lw(int t, int i, int s) { 
  std::cout << "lw $" << t << ", " << i << "($" << s << ")" << "\n"; 
}
void Sw(int t, int i, int s) { 
  std::cout << "sw $" << t << ", " << i << "($" << s << ")" << "\n"; 
}

void Word(int i) {
  std::cout << ".word " << i << "\n";
}
void Word(std::string label) {
  std::cout << ".word " + label + "\n";
}
void Label(std::string name) {
  std::cout << name + ":\n";
}

void push(int s){
    Sw(s, -4, 30);
    Sub(30, 30, 4);
}
void pop(int d){
    Add(30, 30, 4);
    Lw(d, -4, 30);
}
void pop(){
    Add(30, 30, 4);
}

void constant(int d){
    Lis(3);
    Word(d);
}
/*helper*/


class OffsetTable{
    public:
    map<string, int> table;
    void add(string var, int offset){
        table.emplace(var, offset);
    }
};



struct Node {
    // data stored at the node
    std::string data;
    Token t;
    rule r;
    string type = ""; 
    // vector of pointers to child subtrees; could also use smart pointers
    std::vector<Node*> children;
    // constructor for a leaf node
    Node(Token t) : t(t) {}
    Node(rule r) : r(r) {}
    
    //Node(std::istream &in = std::cin) {
    // constructor that builds a tree as it reads input
    //}
    // explicit destructor; could also use smart pointers
    ~Node() {
        if (children.size() == 0){  
            return   ;   
        }else {
            for( auto &c : children ) { delete c; }
        }
    }
    void addChild(Node* child) {
        children.push_back(child);
    }

    Node* getChild(string type, int n){
        for (int i = 0; i < children.size(); i++){
            if (children[i]->t.kind != ""){
                if (children[i]->t.kind == type){
                    n--;
                }
            }
            else{
                if (children[i]->r.LHS == type){
                    n--;
                }
            }
            if (n == 0){
                return children[i];
            }
        }
        return nullptr;
    }

    void print(const std::string prefix = "", std::ostream &out = std::cout) {

        if (t.kind != ""){
        std::cout << t.kind << " " << t.lexeme << std::endl;}
        else{
            std::cout << r.LHS;
            if (r.RHS.size() == 0){
                cout << " .EMPTY";
            }
            for (int i = 0; i < r.RHS.size(); i++){
                cout << " ";
                cout << r.RHS[i];
            }
            cout << endl;
        }

    
        size_t numChildren = children.size();
        /*for (size_t i = 0; i < numChildren; ++i) {
            children[i]->print(prefix);
        }*/
    // prints a representation of the tree, with each line indented by the given prefix
    }

};

void del(Node *n){
    if (n->children.size() == 0){  
        delete n;   
    }else {
        for( auto &c : n->children ) { del(c); }
    }
}



class Variable{
    public:
    string name;
    string type;
    Variable(Node* n){
        name = n->children[1]->t.lexeme;
        if (n->children[0]->r.RHS.size() > 1){
            type = "int*";
        }
        else{
            type = "int";
        }
    }
};

class VariableTable{
    public:
    map<string, Variable> table;
    int add(Variable v){
        //cout << v.name << endl;        
        if (table.count(v.name) > 0){
            return 0;
        }
        else{
            //cout << v.name << endl;
            table.emplace(v.name, v);
            return 1;
        }
    }

    Variable get(string s){
        //cout << s << endl;
        std::map<string, Variable>::iterator it;
        it = table.find(s);
        if (it != table.end()){
            return table.find(s)->second;
        }
        else{
            Variable p(nullptr);
            return p;
        }
    }
};

void func(Node* p, vector<string>& v, VariableTable& vt, OffsetTable& ot, int& d){
    if (p->r.RHS.size() == 1){
        Variable va(p->children[0]);
        v.push_back(va.type);
        if (vt.add(va) == 0){
             
            cerr << "ERROR SEMANTICS 111";
        }
        ot.add(va.name, d);
        d = d+4;
    }
    else{
        Variable va(p->children[0]);
        v.push_back(va.type);
        if (vt.add(va) == 0){
             
            cerr << "ERROR SEMANTICS 11111";
        }
        func(p->children[2], v, vt, ot, d);
        ot.add(va.name, d);
        d = d+4;
    }
}

void func2(Node* p, VariableTable& vt, OffsetTable& ot, int& n){

    if (p->r.RHS.size() == 0){
    }
    else{
        func2(p->children[0], vt, ot, n);
        Variable va(p->children[1]);

        if (p->r.LHS == "dcls" && p->r.RHS[0] == "dcls" && p->r.RHS[3] == "NUM"){
            if (va.type == "int"){
                ot.add(va.name, n);
            }
            else{
                 
                cerr << "ERROR SEMANTICS 109";
            }
        }
        if (p->r.LHS == "dcls" && p->r.RHS[0] == "dcls" && p->r.RHS[3] == "NULL"){
            if (va.type == "int*"){
                ot.add(va.name, n);
            }
            else{
                 
                cerr << "ERROR SEMANTICS 2";
            }
        }


        if (vt.add(va) == 0){
             
            cerr << "ERROR SEMANTICS 9891";
        }
        
        n = n - 4;
    }


    /*if (p->r.RHS.size() == 1){
        Variable va(p->children[0]);
        v.push_back(va.type);
        vt.add(va);
    }
    else{
        Variable va(p->children[0]);
        v.push_back(va.type);
        vt.add(va);
        func(p->children[2], v, vt);
    }*/
}

void helper(Node* n){
    for (int i = 0; i < n->children.size(); i++){
        helper(n->children[i]);
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "lvalue"){
        Node* x = n->getChild("expr", 1);
        Node* y = n->getChild("lvalue", 1);
        if (x->type == y->type){
        }
        else{
             
            cerr << "ERROR SEMANTICS 3";
        }
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "PRINTLN"){
        Node* x = n->getChild("expr", 1);
        if (x->type == "int"){
        }
        else{
             
            cerr << "ERROR SEMANTICS 4";
        }
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "DELETE"){
        Node* x = n->getChild("expr", 1);
        if (x->type == "int*"){
        }
        else{
             
            cerr << "ERROR SEMANTICS 5";
        }
    }
    if (n->r.LHS == "test"){
        Node* x = n->getChild("expr", 1);
        Node* y = n->getChild("expr", 2);
        if (x->type == y->type){
        }
        else{
             
            cerr << "ERROR SEMANTICS 6";
        }
    }
}


void funcHelper(Node *n, vector<string>& types){
    if (n->r.RHS.size() == 1){
        types.push_back(n->children[0]->type);
    }
    else{
        types.push_back(n->children[0]->type);
        funcHelper(n->children[2], types);
    }
}





class Procedure{
    public:
    string name;
    vector<string> signature;
    VariableTable vt;
    OffsetTable ot;
    int c = 0;
    int d = 4;
    Procedure(Node* n){
        if (n->r.LHS == "procedure"){
            name = n->children[1]->t.lexeme;
            if (n->children[3]->r.RHS.size() != 0){
                func(n->children[3]->children[0], signature, vt, ot, d);
            }
            func2(n->children[6], vt, ot, c);
        }
        else{
            Node* x = n->getChild("dcl", 2);
            if (x->children[0]->r.RHS.size() == 1){
            }
            else{
                 
                cerr << "ERROR SEMANTICS 7";
            }
            name = n->children[1]->t.lexeme;
            Variable va(n->children[3]);
            signature.push_back(va.type);
            if (vt.add(va) == 0){
             
            cerr << "ERROR SEMANTICS 1998";
            }
            ot.add(va.name, 8);
            
            Variable va1(n->children[5]);
            signature.push_back(va1.type);
            if (vt.add(va1) == 0){
             
            cerr <<"ERROR SEMANTICS 11";
            }
            ot.add(va1.name, 4);
            
            
            func2(n->children[8], vt, ot, c);
            // pop n times 
        }
    }
};


void nonPara(Node* p, VariableTable& vt, OffsetTable& ot){
    if (p->r.RHS.size() == 0){
    }
    else{
        nonPara(p->children[0], vt, ot);
        if (p->r.LHS == "dcls" && p->r.RHS[0] == "dcls" && p->r.RHS[3] == "NUM"){
            int x = stoi(p->children[3]->t.lexeme);
            constant(x);
            push(3);
            
        }
        if (p->r.LHS == "dcls" && p->r.RHS[0] == "dcls" && p->r.RHS[3] == "NULL"){
            constant(1);
            push(3);
        }    
    }
}

void nonParaPop(Node* p){
    if (p->r.RHS.size() == 0){

    }
    else{
        nonParaPop(p->children[0]);
        pop();
    }
}


void Decl(Node* n, VariableTable& vt, OffsetTable& ot){
    if (n->r.LHS == "procedure"){
        nonPara(n->children[6], vt, ot);
    }
    else{
        push(1);
        push(2);
        Sub(29, 30, 4);
        nonPara(n->children[8], vt, ot);
    }

}



class ProcedureTable{
    public:
    map<string, Procedure> table;
    int add(Procedure v){
        //cout << v.name << endl;
        if (table.count(v.name) > 0){
            return 0;
        }
        else{
            table.emplace(v.name, v);
            return 1;
        }
    }

    Procedure get(string s){
        std::map<string, Procedure>::iterator it;
        it = table.find(s);
        if (it != table.end()){
            return table.find(s)->second;
        }
        else{
            Procedure p(nullptr);
            return p;
        }
    }
};
void Expr(Node*n, OffsetTable& ot, ProcedureTable& pt);



Node* Lvalue(Node*n, OffsetTable& ot){
    if (n->r.RHS.size() == 1 || n->r.RHS.size() == 2){
        return n;   
    }
    else if (n->r.RHS.size() == 3){
        Lvalue(n->children[1], ot);
    }
}

void Arglist(Node* n, OffsetTable& ot, ProcedureTable& pt){
    if (n->r.RHS.size() == 1){
        Expr(n->children[0], ot, pt);
        push(3);
    }
    else{
        Expr(n->children[0], ot, pt);
        push(3);
        Arglist(n->children[2], ot, pt);
    }
}

void ArglistPop(Node* n, OffsetTable& ot, ProcedureTable& pt){
    if (n->r.RHS.size() == 1){
        pop();
    }
    else{
        pop();
        ArglistPop(n->children[2], ot, pt);
    }
}


void Expr(Node*n, OffsetTable& ot, ProcedureTable& pt){
    if (n->r.LHS == "factor" && (n->r.RHS[0] == "ID") &&  n->r.RHS.size() == 1){
        Lw(3, ot.table[n->children[0]->t.lexeme], 29);        
    }
    if (n->r.LHS == "factor" && (n->r.RHS[0] == "NUM" || n->r.RHS[0] == "NULL")){
        if (n->r.RHS[0] == "NUM"){
            int x = stoi(n->children[0]->t.lexeme);
            constant(x);
        }
        else{
            constant(1);
        }
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "NEW"){
        Expr(n->children[3], ot, pt);
        Add(1, 0, 3);
        push(31);
        Lis(5);
        Word("new");
        Jalr(5);
        pop(31);
        Bne(3, 0, 1);
        Add(3, 0, 11);
    }

    if (n->r.LHS == "factor" && n->r.RHS[0] == "STAR"){
        Expr(n->children[1], ot, pt);
        Lw(3, 0, 3);
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "AMP"){
        Node* x = Lvalue(n->children[1], ot);
        if (x->r.RHS.size() == 1){
            Lis(3);
            Word(ot.table[x->children[0]->t.lexeme]);
            Add(3, 29, 3);
        }
        else if (x->r.RHS.size() == 2){
            Expr(x->children[1], ot, pt);
        }

    }
    if (n->r.LHS == "expr" && (n->r.RHS[0] == "expr") && (n->r.RHS[1] == "PLUS")){
        if (n->children[0]->type == "int*" && n->children[2]->type == "int"){
            Expr(n->children[0], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            Mult(3, 4);
            Mflo(3);
            pop(5);
            Add(3, 5, 3);
        }
        else if (n->children[0]->type == "int" && n->children[2]->type == "int*"){
            Expr(n->children[0], ot, pt);
            Mult(3, 4);
            Mflo(3);
            push(3);
            Expr(n->children[2], ot, pt);
            pop(5);
            Add(3, 5, 3);
        }
        else{
            Expr(n->children[0], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            pop(5);
            Add(3, 5, 3);   
        }
        
    }
    if (n->r.LHS == "expr" && n->r.RHS[0] == "expr" && n->r.RHS[1] == "MINUS"){
        if (n->children[0]->type == "int*" && n->children[2]->type == "int"){
            Expr(n->children[0], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            Mult(3, 4);
            Mflo(3);
            pop(5);
            Sub(3, 5, 3);
        }
        else if (n->children[0]->type == "int*" && n->children[2]->type == "int*"){
            Expr(n->children[0], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            pop(5);
            Sub(3, 5, 3);
            Div(3, 4);
            Mflo(3);
        }
        else{
            Expr(n->children[0], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            pop(5);
            Sub(3, 5, 3);   
        }
    }
    if (n->r.LHS == "expr" && n->r.RHS[0] == "term"){
        Expr(n->children[0], ot, pt);
    }
    if (n->r.LHS == "term" && n->r.RHS[0] == "factor"){
        Expr(n->children[0], ot, pt);
    }
    if (n->r.LHS == "term" && n->r.RHS[0] == "term"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        if (n->r.RHS[1] == "STAR"){
            Mult(5, 3);
            Mflo(3);
        }
        if (n->r.RHS[1] == "SLASH"){
            Div(5, 3);
            Mflo(3);
        }
        if (n->r.RHS[1] == "PCT"){
            Div(5, 3);
            Mfhi(3);
        }
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "LPAREN"){
        Expr(n->children[1], ot, pt);
    }

    if (n->r.LHS == "factor" && n->r.RHS[0] == "ID" && n->r.RHS.size() > 1 &&  n->r.RHS[2] == "RPAREN"){
        string pro = n->children[0]->t.lexeme + to_string(1);
        push(29);
        push(31);
        Sub(29, 30, 4);
        Lis(5);
        Word(pro);
        Jalr(5);
        pop(31);
        pop(29);
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "ID" && n->r.RHS.size() > 1 &&  n->r.RHS[2] == "arglist"){
        string pro = n->children[0]->t.lexeme + to_string(1);
        push(29);
        push(31);
        Arglist(n->children[2], ot, pt);
        Sub(29, 30, 4);
        Lis(5);
        Word(pro);
        Jalr(5);
        ArglistPop(n->children[2], ot, pt);
        pop(31);
        pop(29);
    }
}


void Test(Node* n, OffsetTable& ot, ProcedureTable& pt){
    if (n->r.RHS[1] == "EQ"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        Beq(3, 5, 2);
        Add(3, 0, 0);
        Beq(0, 0, 1);
        Add(3, 11, 0);
    }
    if (n->r.RHS[1] == "NE"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        Bne(3, 5, 2);
        Add(3, 0, 0);
        Beq(0, 0, 1);
        Add(3, 11, 0);
    }
    if (n->r.RHS[1] == "LT"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        if (n->children[0]->type == "int"){
            Slt(3, 5, 3);
        }
        else{
            Sltu(3, 5, 3);
        }
    }
    if (n->r.RHS[1] == "LE"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        if (n->children[0]->type == "int"){
            Slt(3, 3, 5);
            Sub(3, 11, 3);
        }
        else{
            Sltu(3, 3, 5);
            Sub(3, 11, 3);
        }
    }
    if (n->r.RHS[1] == "GE"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        if (n->children[0]->type == "int"){
            Slt(3, 5, 3);
            Sub(3, 11, 3);
        }
        else{
            Sltu(3, 5, 3);
            Sub(3, 11, 3);
        }  
    }
    if (n->r.RHS[1] == "GT"){
        Expr(n->children[0], ot, pt);
        push(3);
        Expr(n->children[2], ot, pt);
        pop(5);
        if (n->children[0]->type == "int"){
            Slt(3, 3, 5);
        }
        else{
            Sltu(3, 3, 5);
        }
    }
}

void Statements(Node*n, OffsetTable& ot, int& i, ProcedureTable& pt);


void Statement(Node*n, OffsetTable& ot, int& i, ProcedureTable& pt){
    if (n->r.LHS == "statement" && n->r.RHS[0] == "lvalue"){
        Node* x = Lvalue(n->children[0], ot);
        if (x->r.RHS.size() == 1){
            Expr(n->children[2], ot, pt);
            Sw(3, ot.table[x->children[0]->t.lexeme], 29);
        }
        if (x->r.RHS.size() == 2){
            Expr(x->children[1], ot, pt);
            push(3);
            Expr(n->children[2], ot, pt);
            pop(5);
            Sw(3, 0, 5);
        }

    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "PRINTLN"){
        Expr(n->children[2], ot, pt);
        push(1);
        Add(1, 3, 0);
        push(31);
        Lis(5);
        Word("print");
        Jalr(5);
        pop(31);
        pop(1);
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "WHILE"){
        string loopi = "loop" + to_string(i);
        string endi = "end" + to_string(i);
        i++;
        Label(loopi);
        Test(n->children[2], ot, pt);
        Bne(11, 3, endi);
        Statements(n->children[5], ot, i, pt);
        Beq(0, 0, loopi);
        Label(endi);
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "IF"){
        string elsei = "else" + to_string(i);
        string endifi = "endIf" + to_string(i);
        i++;
        Test(n->children[2], ot, pt);
        Bne(11, 3, elsei);
        Statements(n->children[5], ot, i, pt);
        Beq(0, 0, endifi);
        Label(elsei);
        Statements(n->children[9], ot, i, pt);
        Label(endifi);
    }
    if (n->r.LHS == "statement" && n->r.RHS[0] == "DELETE"){
        string nulli = "Null"+to_string(i);
        i++;
        Expr(n->children[3], ot, pt);
        Add(1, 3, 0);
        Beq(3, 11, nulli);
        push(31);
        Lis(5);
        Word("delete");
        Jalr(5);
        pop(31);
        Label(nulli); 
    }

}

void Statements(Node*n, OffsetTable& ot, int& i, ProcedureTable& pt){
    if(n->r.RHS.size() == 0){
    }
    else if (n->r.RHS[0] == "statements"){
        //i++;
        Statements(n->children[0], ot, i, pt);
        Statement(n->children[1], ot, i, pt);
    }
}



void annotateTypes(Node* n, VariableTable& vt, ProcedureTable& pt, OffsetTable& ot){
    //cout << vt.table.size() << endl;
    for (int i = 0; i < n->children.size(); i++){
        annotateTypes(n->children[i], vt, pt, ot);
    }
    if (n->t.kind == "NUM"){
        n->type = "int";
    }
    if (n->t.kind == "NULL"){
        n->type = "int*";
    }
    if (n->r.LHS == "factor" && (n->r.RHS[0] == "NUM" || n->r.RHS[0] == "NULL")){
        n->type = n->children[0]->type;
    }
    if (n->r.LHS == "factor" && (n->r.RHS[0] == "ID") &&  n->r.RHS.size() == 1){
        //cout << n->children[0]->t.lexeme << endl;
        std::map<string, Variable>::iterator it;
        it = vt.table.find(n->children[0]->t.lexeme);
        if (it == vt.table.end()){
             
                cerr << "ERROR not dec";
        }
        else{
        n->type = (vt.get(n->children[0]->t.lexeme)).type;}
    }
    if (n->r.LHS == "lvalue" && (n->r.RHS[0] == "ID")){
        std::map<string, Variable>::iterator it;
        it = vt.table.find(n->children[0]->t.lexeme);
        if (it == vt.table.end()){
             
                cerr << "ERROR not dec";
        }
         else{
        n->type = vt.get(n->children[0]->t.lexeme).type;}
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "LPAREN"){
        n->type = n->children[1]->type;
    }
    if (n->r.LHS == "lvalue" && n->r.RHS[0] == "LPAREN"){
        n->type = n->children[1]->type;
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "AMP"){
        if (n->children[1]->type == "int"){
            n->type = "int*";
        }
        else{
            cerr << "ERROR SEMANTICS 8";
        }
    }
    if ((n->r.LHS == "lvalue" || n->r.LHS == "factor") && n->r.RHS[0] == "STAR"){
        if (n->children[1]->type == "int*"){
            n->type = "int";
        }
        else{
             
            cerr << "ERROR SEMANTICS 9";
        }
    }
    if (n->r.LHS == "factor" && n->r.RHS[0] == "NEW"){
        if (n->children[3]->type == "int"){
            n->type = "int*";
        }
        else{
             
            cerr << "ERROR SEMANTICS 10";
        }
    }
    // step 5
    if (n->r.LHS == "factor" && n->r.RHS[0] == "ID" && n->r.RHS.size() > 1 &&  n->r.RHS[2] == "RPAREN"){
        string lex = n->children[0]->t.lexeme;
        std::map<string, Variable>::iterator it;
        it = vt.table.find(lex);
        if (it != vt.table.end()){
             
            cerr << "ERROR variable same as procedure";
        }
        else{
            std::map<string, Procedure>::iterator it2;
            it2 = pt.table.find(lex);
            if (it2 == pt.table.end()){
                 
                cerr << "ERROR not dec";
            }
            else{
                Procedure p = pt.get(n->children[0]->t.lexeme);
                if (p.signature.size() == 0){
            n->type = "int";
        }
        else{
             
            cerr << "ERROR signature not empty";
        }
            }
        }

        
        
    }

    if (n->r.LHS == "factor" && n->r.RHS[0] == "ID" && n->r.RHS.size() > 1 && n->r.RHS[2] == "arglist"){
        string lex = n->children[0]->t.lexeme;
        std::map<string, Variable>::iterator it;
        it = vt.table.find(lex);
        if (it != vt.table.end()){
             
            cerr << "ERROR variable same as procedure";
        }
        else{
            std::map<string, Procedure>::iterator it2;
            it2 = pt.table.find(lex);
            if (it2 == pt.table.end()){
                 
                cerr << "ERROR not dec";
            }
            else{
                Procedure p = pt.get(n->children[0]->t.lexeme);
                vector<string> types;
        funcHelper(n->children[2], types);
        if (p.signature.size() != types.size()){
             
            cerr << "ERROR signature not equal types";
        }
        else{
            for (int i = 0; i < types.size(); i++){
                if (types[i] != p.signature[i]){
                     
                    cerr << "ERROR signature not equal types";
                }
            }
            n->type = "int";
        }
            }
        }
        
        
    }


    // add rule
    // step 5
    
    if (n->r.LHS == "term" && n->r.RHS[0] == "factor"){
        
        n->type = n->children[0]->type;

    }
    if (n->r.LHS == "term" && n->r.RHS[0] == "term"){
        if (n->children[0]->type == "int" && n->children[2]->type == "int"){
            n->type = "int";
        }
        else{
             
            cerr << "ERROR SEMANTICS 112";
        }
    }
    if (n->r.LHS == "expr" && n->r.RHS[0] == "term"){
        
        n->type = n->children[0]->type;
    }
    if (n->r.LHS == "expr" && (n->r.RHS[0] == "expr") && (n->r.RHS[1] == "PLUS")){
        
        
        if (n->children[0]->type == "int" && n->children[2]->type == "int"){
            n->type = "int";
        }
        else if (n->children[0]->type == "int*" && n->children[2]->type == "int"){
            n->type = "int*";
        }
        else if (n->children[0]->type == "int" && n->children[2]->type == "int*"){
            n->type = "int*";   
        }
        else{
             

            cerr << "ERROR SEMANTICS 12";
        }
    }
    if (n->r.LHS == "expr" && n->r.RHS[0] == "expr" && n->r.RHS[1] == "MINUS"){
        if (n->children[0]->type == "int" && n->children[2]->type == "int"){
            n->type = "int";
        }
        else if (n->children[0]->type == "int*" && n->children[2]->type == "int"){
            n->type = "int*";
        }
        else if (n->children[0]->type == "int*" && n->children[2]->type == "int*"){
            n->type = "int";   
        }
        else{
             
            cerr << "ERROR SEMANTICS 13";
        }
    }
    
   
    
    

}








void collectProcedures(Node* p, ProcedureTable& pt, int& i){
    if (p->r.RHS.size() == 1){
        
        Procedure pr(p->children[0]);
        
        if (pt.add(pr) == 0){
             
            cerr << "ERROR SEMANTICS 1";
        }
        Decl(p->children[0], pr.vt, pr.ot);
        

        annotateTypes(p->children[0], pr.vt, pt, pr.ot);
        
        helper(p->children[0]);
        if (pr.signature[0] == "int"){
            Add(2, 0, 0);
        }
        push(31);
        Lis(5);
        Word("init");
        Jalr(5);
        pop(31);

        Statements(p->children[0]->getChild("statements", 1), pr.ot, i, pt);

        Node* x = p->children[0]->getChild("expr", 1);
        Expr(x, pr.ot, pt);
        if (x->type == "int"){
        }
        else{
             
            cerr << "ERROR SEMANTICS 14";
        }
        pop();
        pop();
        nonParaPop(p->children[0]->children[8]);
        Jr(31);
    }
    else{
        //cout << "yes" << endl;
        Procedure pr(p->children[0]);
        //p->children[0]->print();
        if (pt.add(pr) == 0){
             
            cerr << "ERROR SEMANTICS 1";
        }
        annotateTypes(p->children[0], pr.vt, pt, pr.ot);
        helper(p->children[0]);
        Node* x = p->children[0]->getChild("expr", 1);
        if (x->type == "int"){
        }
        else{
             
            cerr << "ERROR SEMANTICS 15";
        }
        string proci = p->children[0]->children[1]->t.lexeme + to_string(1);
        i++;
        collectProcedures(p->children[1], pt, i);
        Label(proci);
        Decl(p->children[0], pr.vt, pr.ot);
        Statements(p->children[0]->getChild("statements", 1), pr.ot, i, pt);
        Expr(x, pr.ot, pt);
        nonParaPop(p->children[0]->children[6]);
        Jr(31);
    }
}







void reduceTrees(rule rl, vector<Node*>& treeStack){
    Node *n;
    n = new Node(rl);
    int len = rl.RHS.size();
    int l = (treeStack.size() - len);
    for (int i = l; i < treeStack.size(); i++){
        n->addChild(treeStack[i]);
    }
    //cout << treeStack.back()->t.lexeme;
    int sz = treeStack.size();
    for (int i = l; i < sz; i++){
        treeStack.pop_back();
    }
    //cout << treeStack.back()->t.lexeme;
    treeStack.push_back(n);
}

void reduceStates(rule rl, vector<int>& stateStack, slrDFA &sld){
    int len = rl.RHS.size();
    for (int i = 0; i < len; i++){
        stateStack.pop_back();
    }
    string lhs = rl.LHS;
    int s = stateStack.back();
    int new1 = sld.transitions.find(make_pair(s, lhs))->second;
    stateStack.push_back(new1);
}

void shift(Token t, vector<Node*>& treeStack, vector<int>& stateStack, slrDFA &sld){
    Node *n;
    n = new Node(t);
    treeStack.push_back(n);
    std::map<pair<int, string>, int>::iterator it;
    int s = stateStack.back();
    string lhs = t.kind;
    it = sld.transitions.find(make_pair(s, lhs));
    if (it == sld.transitions.end()){
        for (int i =0; i < treeStack.size(); i++){
            delete treeStack[i];
        }
        
        throw std::runtime_error
        ("ERROR transition not found");
    }
    else{
        int new1 = sld.transitions.find(make_pair(s, lhs))->second;
        stateStack.push_back(new1);
    }
}

void TokenToTrees(deque<Token> input, vector<Node*>& treeStack){
    Node *n;
    for (int i = 0; i < input.size(); i++){
        n = new Node(input[i]);
        treeStack.push_back(n);
    }
}





int main(){
    try{
    stringstream a(WLP4_CFG);
    stringstream b(WLP4_DFA);
    CFG cfg(a);
    slrDFA slr(b);
    deque<Token> input;
    vector<Node*> treeStack;
    treeStack.clear();
    string line;
    vector<int> stateStack;
    stateStack.emplace_back(0);
    while (getline(cin, line)) {
        istringstream iss(line);
        string kind;
        string lexeme;
        iss >> kind;
        iss >> lexeme;

        Token t(kind, lexeme);
        input.emplace_back(t);
    }
    Token st("BOF", "BOF");
    input.push_front(st);
    Token ed("EOF", "EOF");
    input.push_back(ed);
    //TokenToTrees(input, treeStack);
    /*rule rl("dcls .EMPTY");
    for (int i = 0; i < treeStack.size(); i++){
        treeStack[i]->print();
    } 
    reduceTrees(rl, treeStack);
    for (int i = 0; i < treeStack.size(); i++){
        treeStack[i]->print();
    }*/

    for (int i = 0; i < input.size(); i++){
        string symbol = input[i].kind;
        int top = stateStack.back();
        std::map<pair<int, string>, int>::iterator it;
        it = slr.reductions.find(make_pair(top, symbol));
        if (it != slr.reductions.end()){
            int new1 = slr.reductions.find(make_pair(top, symbol))->second;
            reduceTrees(cfg.rules[new1], treeStack);
            reduceStates(cfg.rules[new1], stateStack,slr);
            i--;
            continue;
        }
        else{
            shift(input[i], treeStack, stateStack, slr);
        }
    }
    reduceTrees(cfg.rules[0], treeStack);
    //treeStack[0]->print();
    /*for (int i = 0; i < treeStack.size(); i++){
        treeStack[i]->print();
    }*/
    cout << ".import print" << endl;
    cout << ".import init" << endl;
    cout << ".import new" << endl;
    cout << ".import delete" << endl;
    Lis(4);
    Word(4);
    Lis(11);
    Word(1);
    ProcedureTable pt;
    int i = 0;
    collectProcedures(treeStack[0]->children[1], pt, i);
    for (int i =0; i < treeStack.size(); i++){
            delete treeStack[i];
    }
    }
    catch(std::runtime_error &e) {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 1;
    }
    return 0;
}



