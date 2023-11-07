#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
 
 bool isPrime(int n){
   
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }   
    return true;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> answer;
    vector<int> prime; 
    vector<int> A = number;
    int count = 0;
    for(int i = 1; count<q; i++)
        {
        
            if(isPrime(i))
            {
                prime.push_back(i);
                count++;
            }
        }
        
    for (int i=0; i<q; i++){
        vector<int>Ai;
        vector<int>B;

        while (!A.empty()) {
            if (A[A.size()-1] % prime[i] != 0){
                int num = A[A.size()-1];
                Ai.push_back(num);
                A.pop_back();
            }
            
            else {
                int num = A[A.size()-1];
                B.push_back(num);
                A.pop_back();
            }
             
        }
        while (!B.empty()) {
                int num = B[B.size()-1];
                answer.push_back(num);
                B.pop_back();
            }
        A = Ai;              
    }
    while (!A.empty()) {
        int num = A[A.size()-1];
        answer.push_back(num);
        A.pop_back();
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
