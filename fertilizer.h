//fertilizer.h

//硫酸铵，氯化铵，碳酸氢铵，氨水，液体氨
//(NH4)2SO3, NH4Cl, (NH4)2CO3, NH3
//硝酸钠，硝酸钙
//NaNO3, Ca(NO3)2
//硝酸铵，硝酸铵钙，硫硝酸铵
//NH4NO3,5Ca(NO3)2•NH4NO3•10H2O，NH4NO3•(NH4)2SO4
//尿素，氰氨化钙
//CO(NH2)2，CaCN2

//过磷酸钙，重过磷酸钙，钙镁磷肥，磷酸一铵，磷酸二铵，磷酸二氢铵，磷酸二氢钙，磷酸二氢钾
//硫磷二铵，亚磷酸钾

//氯化钾，硫酸钾，硝酸钾，磷酸二氢钾，亚磷酸钾，碳酸钾，
//糖醇钾，黄腐酸钾，腐植酸钾



//碳酸钙，柠檬酸钙，硝酸钙，过磷酸钙，重过磷酸钙，钙镁磷肥，氰氨化钙

//氯化镁，硝酸镁，硫酸镁，钙镁磷肥

//硫酸钾，硫酸镁，硫酸铵，过磷酸钙



//硫酸亚铁，三氯化铁，螯合铁

//硫酸锰，碳酸锰，氯化锰，硝酸锰，螯合锰

//硫酸铜，碱式硫酸铜，氧化亚铜，氯化铜，螯合铜

//1水硫酸锌，7水硫酸锌，氧化锌，氯化锌，硝酸锌，螯合锌

//硼砂，硼酸

//钼酸铵，钼酸钠

#include <vector>
using namespace std;

vector<Fertilizer> Ferti[50];
Fertilizer * Ferti_name[200];  // 放肥料的指针

struct Fertilizer{
	
	char name[];                //how to input chinese?
	char chem_form[99];
    
    bool  elements[17];         // 
    
    
    //加一个求最大公约数的函数
  
    int numbers[17];
    int   ratio[17];

};



//----------------------
//  N  P  K
//  Ca Mg S
//  Fe Zn Mn Cu B Mo Cl
//----------------------

element *elements[17];


struct element{
    
    vector<*Fertilizer> ferti[];     //point to the fertilizer which contains this element
    vector<int>         perce[];     //element percentage	

}N, P, K,Ca, Mg, S,Fe, Zn, Mn, Cu, B, Mo, Cl;



element * P_element[13];

P_element [0] = &N;
P_element [1] = P;
P_element [2] = K;

P_element [3] = Ca;
P_element [4] = Mg;
P_element [5] = S;

P_element [6] = Fe;
P_element [7] = Zn;
P_element [8] = Mn;
P_element [9] = Cu;
P_element[10] = B;
P_element[11] = Mo;
P_element[12] = Cl;



int add_ferti(int element, char name[99]){

element * target[5];
int i,total;
bool exist[13];

for(i=0;i<5;i++) target[i] = NULL;

i = 0;
total = 0;

for(j=0;j<13;j++){
    exist[j] = false;
    total += element[j];
    if(element[j])  {exist[j] = true; target[i++] = P_element[j];}       ??????可以这么写吗？
}




}







// Function 

int * search_ferti(Fertilizer * given_ferti[10],int aim_element[17],){

// 


// search some fertilizers that might fit , use a while loop to do the following steps.


// calculate the ratio of elements 
// in the case of different fertilizer weight ratios.
// if in all cases the aim ratio couldn't be reached,
// return an enpty pointer.

    while(!*next) {
    
    //检索所有肥料，比例高的和比例低的都找到，这个问题没那么复杂，
    //一种肥料最多含三种目标元素，常见肥料最多上百种，穷举能搞定
    //可先尝试回溯算法

    }


// A switch statement might help in some situations.

}



