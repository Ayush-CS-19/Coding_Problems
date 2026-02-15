class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        string k = "";
        int i = 0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(i  <= a.size() - 1  && i <= b.size() -1 ){
            if(a[i] == '1' && b[i] == '1' && carry == '0'){
                carry ='1';
                k += '0';
            }
            else if(a[i] == '1' && b[i] == '1' && carry == '1'){
                carry = '1';
                k += '1';
            }
            else if(a[i] == '1' && b[i] == '0' && carry == '1'){
                k += '0';
                carry = '1';
            }
            else if(a[i] == '0' && b[i] == '1' && carry == '1'){
                k += '0';
                carry = '1';
            }
            else if(a[i] == '1' && b[i] == '0' && carry == '0'){
                k += '1';
                carry = '0';
            }
            else if(a[i] == '0' && b[i] == '1' && carry == '0'){
                k += '1';
                carry = '0';
            }
            else if(a[i] == '0' && b[i] == '0' && carry == '1'){
                k += '1';
                carry = '0';
            }
            else{
                k += '0';
          }
            i++;
        }
        while(i <= a.size() - 1){
            if(carry == '1' && a[i] =='1'){
                k += '0';
                carry = '1';
            }
            else if(carry == '1' && a[i] == '0'){
            k += '1';
            carry = '0';
            }
            else if(carry == '0' && a[i] == '1'){
                k += '1';
            }
            else{
                k += '0';
            }
            i++;
        }
                while(i <=  b.size() -1){
            if(carry == '1' && b[i] =='1'){
                k += '0';
                carry = '1';
            }
            else if(carry == '1' && b[i] == '0'){
            k += '1';
            carry = '0';
            }
            else if(carry == '0' && b[i] == '1'){
                k += '1';
            }
            else{
                k += '0';
            }
            i++;
        }
        if(carry == '1'){
            k += '1';
        }
        reverse(k.begin(),k.end());
        return k;
    }
};