#include <iostream>
#include <vector>
#include <map>
#include <set>


static const bool dbg = true;
using namespace std;
#define dout if(dbg)cout
const vector<string> tokens{"1", "2", "3", "4", "5", "blue", "green", "red", "white", "yellow", "anna", "bernhard",
                            "chris", "david", "ellen", "danish", "finnish", "icelandic", "norwegian", "swedish", "amiga",
                            "atari", "linux", "mac", "windows", "c", "c++", "java", "pascal", "perl"};
const vector<string> operators{"same-as", "left-of", "right-of", "next-to"};
map<string, int> encode;
map<int, string> decode;
map<string, int> encodeop;
map<int, string> decodeop;

void init() {
    int i=0;
    for(auto it=tokens.begin(); it!=tokens.end(); ++it) {
        encode[*it] = i;
        decode[i] = *it;
        ++i;
    }
    i = 0;
    for(auto it=operators.begin(); it!=operators.end(); ++it) {
        encodeop[*it] = i;
        decodeop[i] = *it;
        ++i;
    }
}


int encode_fact(const string& left, const string& op, const string& right) {
    int answer = encode[left];
    answer <<= 2;
    answer |= encodeop[op];
    answer <<= 5;
    answer |= encode[right];
    return answer;
}

string decode_fact(int code) {
    const int FIVEMASK = (1<<5)-1;
    const int TWOMASK = (1<<2)-1;
    string right = decode[code&FIVEMASK];
    code >>=5;
    string op = decodeop[code&TWOMASK];
    code >>=2;
    string left = decode[code&FIVEMASK];
    return left + " " + op + " " + right;
}


template<typename T>
void print_facts(T begin, T end) {
    for(auto it = begin; it!=end; ++it) {
        cout << decode_fact(*it) << endl;
    }
}


vector<int> read_input() {
    int N;
    cin >> N;
    string left,op, right;
    vector<int> facts;
    for(int i=0; i<N; i++) {
        cin >> left >> op >> right;
        facts.emplace_back(encode_fact(left, op, right));
    }
    return facts;
}

void solve(int N) {
    vector<int> facts = read_input();
    cout << "scenario #" << N << ": ";
}


int main() {
    cin.sync_with_stdio(false);
    init();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        solve(i+1);
    }
}

