void square_num(int n);
void alpha_square(int n1);
void continuous_num(int n3);
void star_square_pattern(int n4);
void star_triangle_pattern(int n5);
void repeat_num_tri(int n6);
void repeat_alpha_tri(int n7);
void incremental_triange(int n8);
void reverse_triangle(int n9);

#include<iostream>
using namespace std;
int main(){
    square_num(4);
    alpha_square(4);
    continuous_num(3);
    star_square_pattern(4);
    star_triangle_pattern(4);
    repeat_num_tri(4);
    repeat_alpha_tri(4);
    incremental_triange(4);
    reverse_triangle(4);
}

// Square Pattern
/*
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/
void square_num(int n){
    cout<<"Square Pattern\n";
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void alpha_square(int n1){
    cout<<endl;
    cout<<"Alpha Square Pattern\n";
    for(int i=0;i<n1;i++){
        char ch='A';
        for(int j=1;j<=n1;j++){
            cout<<ch;
            ch+=1;
        }
        cout<<endl;
    }
}


/*
Continuous Number Pattern
1 2 3 4
5 6 7 8
9 10 11 
12 13 14 
*/
void continuous_num(int n3){
    cout<<endl;
    cout<<"Continuous Num Square"<<endl;
    int num=1;
    for (int i=0;i<n3;i++){
        for(int j=1;j<=n3;j++){
            cout<<num;
            num++;
        }
        cout<<endl;
    }
}

/*Triangle Pattern
* * * *
* * * *
* * * *
* * * *
*/

void star_square_pattern(int n4){
    cout<<endl;
    cout<<"Star Square Pattern"<<endl;
    for(int i=0;i<n4;i++){
        for(int j=0;j<n4;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

/*Triangle Pattern
* 
* *
* * *
* * * *
*/

void star_triangle_pattern(int n5){
    cout<<endl;
    cout<<"Star Triangle Pattern"<<endl;
    for(int i=0;i<n5;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}


/* Repeating Numbers in Triangle
1
2 2
3 3 3
4 4 4 4
*/

void repeat_num_tri(int n6){
    cout<<endl;
    cout<<"Repeating Numbers in Triangle"<<endl;
    int repeating_num=1;
    for(int i=0;i<n6;i++){
        for(int j=0;j<i+1;j++){
            cout<<repeating_num;
        }
        repeating_num++;
        cout<<endl;
    }
}

/*Repeating Alphabet Triangle
A
B B
C C C
D D D D
*/

void repeat_alpha_tri(int n7){
    cout<<endl;
    cout<<"Repeating Alphabets in Triangle"<<endl;
    char repeating_alpha='A';
    for(int i=0;i<n7;i++){
        for(int j=0;j<i+1;j++){
            cout<<repeating_alpha;
        }
        repeating_alpha+=1;
        cout<<endl;
    }
}

/*Incremental Triangle
1
1 2
1 2 3
1 2 3 4*/

void incremental_triange(int n8){
    cout<<endl;
    cout<<"Incremental Triangle"<<endl;
    for(int i=0;i<n8;i++){
        for(int j=1;j<i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
}

/*Reverse Triangle 
1
2 1
3 2 1
4 3 2 1 
*/

void reverse_triangle(int n9){
    cout<<endl;
    cout<<"Reverse Triangle Pattern"<<endl;
    for(int i=0;i<n9;i++){
        for(int j=i+1;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}