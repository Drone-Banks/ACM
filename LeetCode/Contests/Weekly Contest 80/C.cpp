class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<int> cut;
        bool zero = true;
        for(int i=1;i<S.length()-2;i++)
        {
            if(S[i] != '0') zero = false; 
            if(zero && i != 1) continue;
            // if(S[i+1]=='0' && S[i+2]=='0') continue;
            cut.push_back(i);
        }
        vector<string> ans;
        for(int c : cut)
        {
            cout << c << endl;
            string a = S.substr(1, c), b = S.substr(c+1, S.length()-2-c);
            bool az = a[0]=='0', bz = b[0]=='0';
            for(int i=0;i<a.length();i++)
            {
                string aa = a;
                if(i!=a.length()-1) {
                    aa.insert(aa.begin()+i+1, '.');
                    if( aa[aa.length()-1] == '0' ) continue;
                } 
                else if(aa.length()>1 && aa[0]=='0') continue;
                for(int j=0;j<b.length();j++)
                {
                    string bb = b;
                    if(j!=b.length()-1) {
                        bb.insert(bb.begin()+j+1, '.');
                        if( bb[bb.length()-1] == '0' ) continue;
                    } 
                    else if(bb.length()>1 && bb[0]=='0') continue;
                    string tmp = "(" + aa + ", " + bb + ")";
                    cout << tmp << endl;
                    ans.push_back(tmp);
                    if(bz) break;
                }
                if(az) break;
            }
        }
        return ans;
    }
};