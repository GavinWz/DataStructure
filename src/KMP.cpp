#include<iostream>

using namespace std;

void set_next(string sub, int* next){
    int length = sub.length();
    next[0] = 0;
    for(int i = 1; i< length; i++){
        int p = 1, q = 0;
        while(p < i){
            if(sub[p] == sub[q]){
                // cout << "sub[" << p << "] = " << sub[p] << "   sub[" << q << "] = " << sub[q] << endl;
                p++; q++;
            }
            else{
                // cout << "sub[" << p << "] = " << sub[p] << "   sub[" << q << "] = " << sub[q] << endl;
                p = p - q + 1;
                q = 0;
            }
            
        }
        // cout << q << endl;
        next[i] = q;
    }
}

bool kmp(string s, string sub, int* next){
    int len1 = s.length();
    int len2 = sub.length();
    int i = 0, j = 0;
    while(i < len1){
        if(s[i] == sub[j]){     //适配, 子母串指针一并后移
            i++, j++;
            if(j >= len2){
                return true;
            }
        }
        else{       //失配,字串指针移动到规定位置,母串指针若非零则不动
            j = next[j];
            if(j == 0)
                i++;
        }
    }
    return false;
}

int main(){
    string s = "abaabaabcabaabc";
    string sub = "aab";
    int length = sub.length();
    int* next = new int[length];
    set_next(sub, next);
    cout << kmp(s, sub, next);
}