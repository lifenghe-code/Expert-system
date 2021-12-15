//@Information building 204,written by fenghe_li
// 2021/12/15
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
map<int,string>map_animal;
void map_initialization();                   //map初始化
bool judge_exist(int num, vector<int> tmp);  //判断是否存在
void intermediate_conclusion(vector<int> tmp);  //生成中间结论
void judge_animal(vector<int> tmp);    //判断动物类型
int main() 
{
    map_initialization();
    vector<int> Preconditions; //储存用户输入的前置条件
    //首先先根据前置条件产生中间结论，如果产生新结论则加入，否则不加
    int input_num;
    while (true)
    {
        cout << "请输入条件，输入 0 结束" << endl;
        cin >> input_num;
        if (input_num != 0)
            Preconditions.push_back(input_num);
        else
            break;
    }
    cout<<"输入的条件为：\n";
    for(auto it:Preconditions){
        cout<<map_animal[it]<<endl;
    }
    intermediate_conclusion(Preconditions);
    cout<<"判断结果为：\n";
    judge_animal(Preconditions);
    system("pause");
    return 0;
}

bool judge_exist(int num, vector<int> tmp) //判断是否存在
{
    vector<int>::iterator it; //迭代器
    it = find(tmp.begin(), tmp.end(), num);
    if (it == tmp.end())
    {
        return false;
    }
    else
        return true;
}
void intermediate_conclusion(vector<int> tmp)
{
    if (judge_exist(1, tmp))
    { //有毛发
        if (!judge_exist(21, tmp))
            tmp.push_back(21); //该动物是哺乳动物
    }
    else if (judge_exist(2, tmp))
    { //有奶
        if (!judge_exist(21, tmp))
            tmp.push_back(21); //该动物是哺乳动物
    }
    else if (judge_exist(3, tmp))
    { //有羽毛
        if (!judge_exist(22, tmp))
            tmp.push_back(22); //该动物是鸟类
    }
    else if (judge_exist(4, tmp))
    { //会飞
        if (judge_exist(5, tmp))
        { //会下蛋
            if (!judge_exist(22, tmp))
                tmp.push_back(22); //该动物是鸟类
        }
    }
    else if (judge_exist(6, tmp))
    { //吃肉
        if (!judge_exist(23, tmp))
            tmp.push_back(23); //食肉类
    }
    else if (judge_exist(7, tmp))
    { //有犬齿
        if (judge_exist(8, tmp))
        { //有爪
            if (judge_exist(9, tmp))
            { //眼盯前方
                if (!judge_exist(23, tmp))
                    tmp.push_back(23); //食肉类
            }
        }
    }
    if (judge_exist(21, tmp))
    { //哺乳动物
        if (judge_exist(10, tmp))
        { //有蹄
            if (!judge_exist(24, tmp))
                tmp.push_back(24); //蹄类
        }
    }
    if (judge_exist(21, tmp))
    { //哺乳动物
        if (judge_exist(11, tmp))
        { //反刍
            if (!judge_exist(24, tmp))
                tmp.push_back(24); //蹄类
        }
    }
}

void judge_animal(vector<int> tmp)
{
    if (judge_exist(21, tmp) && judge_exist(23, tmp) && judge_exist(12, tmp) && judge_exist(13, tmp))
    {
        cout << "金钱豹\n";
    }
    else if (judge_exist(21, tmp) && judge_exist(23, tmp) && judge_exist(12, tmp) && judge_exist(14, tmp))
    {
        cout << "老虎\n";
    }
    else if (judge_exist(24, tmp) && judge_exist(15, tmp) && judge_exist(16, tmp) && judge_exist(13, tmp))
    {
        cout << "长颈鹿\n";
    }
    else if (judge_exist(24, tmp) && judge_exist(14, tmp))
    {
        cout << "斑马\n";
    }
    else if (judge_exist(22, tmp) && judge_exist(15, tmp) && judge_exist(16, tmp) && judge_exist(17, tmp) && judge_exist(17, tmp) && judge_exist(19, tmp))
    {
        cout << "鸵鸟\n";
    }
    else if (judge_exist(22, tmp) && judge_exist(18, tmp) && judge_exist(17, tmp) && judge_exist(19, tmp))
    {
        cout << "企鹅\n";
    }
    else if (judge_exist(22, tmp) && judge_exist(20, tmp))
    {
        cout << "信天翁\n";
    }
    else
    {
        cout << "error，无法判断\n";
    }
}

void map_initialization()
{
    map_animal[1]="有毛发";map_animal[2]="产奶";map_animal[3]="有羽毛";map_animal[4]="不会飞";
    map_animal[5]="会下蛋";map_animal[6]="吃肉";map_animal[7]="有犬齿";map_animal[8]="有爪";
    map_animal[9]="眼盯前方";map_animal[10]="有蹄";map_animal[11]="反刍";map_animal[12]="黄褐色";
    map_animal[13]="有斑点";map_animal[14]="有黑色条纹";map_animal[15]="长脖";map_animal[16]="长腿";
    map_animal[17]="不会飞";map_animal[18]="会游泳";map_animal[19]="黑白二色";map_animal[20]="擅飞";
    map_animal[21]="哺乳类";map_animal[22]="鸟类";map_animal[23]="食肉类";map_animal[24]="蹄类";
}