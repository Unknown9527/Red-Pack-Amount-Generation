#include <random>
#include <iostream>
#include <vector>

using namespace std;

class fenHongBao{
public:
    vector<int> randNumGenerate(int left, int right, int num);
    void printIntVec(vector<int> input);
    void printFloatVec(vector<float> input);
    vector<int> hongBaoMoneyFix(vector<int> inputVec, int sum);
    vector<float> hongBaoAccurateFix(vector<int> input);
};

vector<int> fenHongBao::randNumGenerate(int low, int high, int num){
    vector<int> randNumVec;
    low = low * 100;
    high = high * 100;
    random_device rand;
    mt19937 randMachine(rand());
    uniform_int_distribution<> dist(low, high);
//    uniform_real_distribution<> dist(left, right);
    for(int i = 0; i < num; i++){
        randNumVec.push_back(dist(randMachine));
    }
    return randNumVec;
}

void fenHongBao::printIntVec(vector<int> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

void fenHongBao::printFloatVec(vector<float> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

vector<int> fenHongBao::hongBaoMoneyFix(vector<int> inputVec, int sum){
    int curSum = 0;
    for(int i = 0; i < inputVec.size(); i++){
        curSum = curSum + inputVec[i];
    }
    int diff = sum * 100 - curSum;
    inputVec.push_back(diff);
    return inputVec;
}

vector<float> fenHongBao::hongBaoAccurateFix(vector<int> input){
    vector<float> ans;
    for(int i = 0; i < input.size(); i++){
        float fixRes = input[i];
        ans.push_back(fixRes / 100);
//        cout << fixRes / 100 << " ";
    }
//    cout<<endl;
    return ans;
}

int main() {
    fenHongBao solution;
    
    int totalMoney = 150;
    int hongBaoNum = 10;
    
    vector<int> ans = solution.randNumGenerate(totalMoney / hongBaoNum - 1, totalMoney / hongBaoNum + 1, hongBaoNum - 1);
//    solution.printIntVec(ans);
    
    vector<int> fixAns = solution.hongBaoMoneyFix(ans, totalMoney);
//    solution.printIntVec(fixAns);
    
    vector<float> finalAns = solution.hongBaoAccurateFix(fixAns);
    solution.printFloatVec(finalAns);
    
//    simple test:
//    float checkOutputSum = 0;
//    for(int i = 0; i < finalAns.size(); i++){
//        checkOutputSum += finalAns[i];
//    }
//    cout << checkOutputSum << endl;
    
    return 0;
}
