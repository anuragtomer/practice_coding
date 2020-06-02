#include <iostream>
#include <vector>

using namespace std;
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

// ll t;  cin>>t; while(t--)
int main() {
  string s, t;
  cin >> s >> t;
  string S[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
  for (int i = 0; i < t.length(); i++) {
    bool b = true;
    for (int j = 0; j < 3; j++)
      if (b)
        for (int k = 0; k < 10; k++)
          if (S[j][k] == t[i]) {
            if (s == "R")
              t[i] = S[j][k - 1];
            else
              t[i] = S[j][k + 1];
            b = false;
            break;
          }
  }
  cout << t << "\n";
  return 0;
}
/*
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char ch;
  int sign;
  cin >> ch;
  if (ch == 'R')
    sign = 1;
  else
    sign = -1;
  string s;
  cin >> s;
  string msg;
  for (auto &ch : s) {
    if (sign == -1) {
      switch (ch) {
        case 'q':
          msg.push_back('w');
          break;
        case 'w':
          msg.push_back('e');
          break;
        case 'e':
          msg.push_back('r');
          break;
        case 'r':
          msg.push_back('t');
          break;
        case 't':
          msg.push_back('y');
          break;
        case 'y':
          msg.push_back('u');
          break;
        case 'u':
          msg.push_back('i');
          break;
        case 'i':
          msg.push_back('o');
          break;
        case 'o':
          msg.push_back('p');
          break;
        case 'p':
          break;
        case 'a':
          msg.push_back('s');
          break;
        case 's':
          msg.push_back('d');
          break;
        case 'd':
          msg.push_back('f');
          break;
        case 'f':
          msg.push_back('g');
          break;
        case 'g':
          msg.push_back('h');
          break;
        case 'h':
          msg.push_back('j');
          break;
        case 'j':
          msg.push_back('k');
          break;
        case 'k':
          msg.push_back('l');
          break;
        case 'l':
          msg.push_back(';');
          break;
        case ';':
          break;
        case 'z':
          msg.push_back('x');
          break;
        case 'x':
          msg.push_back('c');
          break;
        case 'c':
          msg.push_back('v');
          break;
        case 'v':
          msg.push_back('b');
          break;
        case 'b':
          msg.push_back('n');
          break;
        case 'n':
          msg.push_back('m');
          break;
        case 'm':
          msg.push_back(',');
          break;
        case ',':
          msg.push_back('.');
          break;
        case '.':
          msg.push_back('/');
          break;
        case '/':
          break;
      }
    } else {
      switch (ch) {
        case 'q':
          break;
        case 'w':
          msg.push_back('q');
          break;
        case 'e':
          msg.push_back('w');
          break;
        case 'r':
          msg.push_back('e');
          break;
        case 't':
          msg.push_back('r');
          break;
        case 'y':
          msg.push_back('t');
          break;
        case 'u':
          msg.push_back('y');
          break;
        case 'i':
          msg.push_back('u');
          break;
        case 'o':
          msg.push_back('i');
          break;
        case 'p':
          msg.push_back('o');
          break;
        case 'a':
          break;
        case 's':
          msg.push_back('a');
          break;
        case 'd':
          msg.push_back('s');
          break;
        case 'f':
          msg.push_back('d');
          break;
        case 'g':
          msg.push_back('f');
          break;
        case 'h':
          msg.push_back('g');
          break;
        case 'j':
          msg.push_back('h');
          break;
        case 'k':
          msg.push_back('j');
          break;
        case 'l':
          msg.push_back('k');
          break;
        case ';':
          msg.push_back('l');
          break;
        case 'z':
          break;
        case 'x':
          msg.push_back('z');
          break;
        case 'c':
          msg.push_back('x');
          break;
        case 'v':
          msg.push_back('c');
          break;
        case 'b':
          msg.push_back('v');
          break;
        case 'n':
          msg.push_back('b');
          break;
        case 'm':
          msg.push_back('n');
          break;
        case ',':
          msg.push_back('m');
          break;
        case '.':
          msg.push_back(',');
          break;
        case '/':
          msg.push_back('.');
          break;
      }
    }
  }
  cout << msg;
  return 0;
}
 */