

#include <iostream>

using namespace std;

int * count_ligand(char form[100], int num);

char * get_formula(){

    int  count;
    char form[100];

	cout<< "What is the chemical formula?" << endl;
	cin>> form;
    cout<< "Got the formula"<<endl;

    return form;
}



// char read_formula(char file_name){

// }


int * count_formula(char form[100]){
    
    int  num,i,j,k,l,m,li,start;

    char     formula[100];
    char      ligand[100];
    int     point[30]={0};
    int     count[17]={0};

    int * cl;

    j     = 0;
    num   = 0;
    start = 0;
    for(i=0;i<100;i++) formula[i] = form[i];


    for(i=0;i<100;i++) {if(formula[i]!='\0') num++;  else break;}

    for(i=0;i<num;i++)  if(formula[i]=='/')  point[j++] = i;

    if(point[0]==0) {

        cl = count_ligand(formula, num); 

        for(m=0;m<17;m++)    count[m] = *(cl + m);

        return count;
    }



    point[j] = num - 1;

    for(i=0;i<=j;i++){

        for(li=0;li<100;li++) ligand[li] = '\0';
    
        for(k=start;k<point[i];k++)    ligand[l] = formula[k]; 

        cl = count_ligand(ligand, num); 

        for(m=0;m<17;m++)     count[m] += *(cl + m);
        
        start = point[i] + 1;      
    }

    return count;
}


//  C  H  O
//  N  P  K
//  Ca Mg S
//  Fe Zn Mn Cu B Mo Cl
//
//----------------------------------------------------------------------------------

int * count_ligand(char form[100], int num){
    
    int i,j,n;
    int count,factor,digit,complex;

    char cha,E,e;       // elements
    char element[2];
    bool Is_double, Is_number, Is_capital;

    int Number_Total[17]={0};
    int Number_Single[8]={0};
    int Number_double[9]={0};

    char Single_elements[8] =  {'C','H','O','N','P','K','S','B'}  ;
    char double_elements[9][3] =  {"Ca","Mg","Fe","Zn","Mn","Cu","Mo","Ni","Cl"}  ;

    
    i = 0;
    j = 0;
    digit  = 1;
    count  = 1;
    factor = 1; 
    complex= 1;



while(i<num){

    Is_number  = false;
    Is_capital = false;
    
    cha = form[num-++i];                       cout<< "lig:"<<cha<<endl;

    if(cha == ')') {factor = count; count = 1; continue;}
    if(cha == '(') {factor = 1; continue;}

//-------------------------------------
// to recognize numbers and
// count the number of each element
// if the number is larger than 1.
//-------------------------------------
    for(n=0;n<=9;n++)  {

        if(n == (cha - '0')) {

            
            Is_number=true; 

            count = count + ( cha - 48 )*digit ;

cout<< "number:"<<count<<endl;

            digit=digit*10; 
            
            break;
        } 
    }

    if(Is_number) continue;


//---------------------------
// to recognize each element
//---------------------------
    if(cha>='A' && cha<='Z')   Is_capital = true;


    if(Is_capital) {

        element[0] = cha;

        // for elements presented with one letter

        if(!(element[1]>='a' && element[1]<='z')){
            for(j=0;j<8;j++){
        		if(Single_elements[j] == element[0]){

                    
                    if(count!=1) count--;
         			Number_Single[j] = count * factor; 
                    
                    
                    cout<<"Single:"<<element[0]<<element[1]<<endl;



                    count = 1; digit = 1;
         		    element[0] = '\0'; element[1] = '\0';
         		    break;
         		}
         	}
       	}

        // for elements presented with two letters

        else  for(j=0;j<9;j++){
        	    if(double_elements[j][0]==element[0] && double_elements[j][1]==element[1]){ 

                    if(count!=1) count--;
                    Number_double[j] = count * factor;


                    cout<< "Double:"<<element[0]<<element[1]<<endl;


                    count = 1; digit = 1;
       			    element[0] = '\0'; element[1] = '\0';
         		    Is_double = false;
         		    continue;
         	    }         
            }

    }
        
    else {
        cout<< "lower case!"<<endl;
         	element[1] = cha; 
            Is_double = true;
         	continue;
    }
}


for(i=0;i<8;i++)  Number_Total[i] = Number_Single[i];
for(i=8;i<17;i++) Number_Total[i] = Number_double[i-8];

return Number_Total;

}

//----------------------------------------------------------------------------------




