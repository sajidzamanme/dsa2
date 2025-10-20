#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    string name;
    float price;
    float weight;
    float priceByWeight;
    float portionTaken;

    Item(string name,float price, float weight){
        this->name=name;
        this->price=price;
        this->weight=weight;
        this->priceByWeight=this->price/this->weight;
    }
};

bool comparator(Item a, Item b){
    if(a.priceByWeight>b.priceByWeight){
        return true;
    }else{
        return false;
    }
}

void fractionalKnapsack(vector <Item> itemsVector,int n,int C){
    sort(itemsVector.begin(),itemsVector.end(),comparator);
//    cout<<"After sorting:"<<endl;
//    for(Item item:itemsVector){
//        cout<<"(name="<<item.name<<",price="<<item.price<<",weight="<<item.weight<<",priceByWeight="<<item.priceByWeight<<endl;
//    }
    vector <Item> selectedItemsVector;
    float profit = 0;
    int i = 0;

    while(C>0 && i<=n-1){
        if(C>=itemsVector[i].weight){
            C=C-itemsVector[i].weight;
            profit = profit+itemsVector[i].price;
            itemsVector[i].portionTaken=1;
            selectedItemsVector.push_back(itemsVector[i]);
        }else{
            profit = profit+C*itemsVector[i].priceByWeight;
            itemsVector[i].portionTaken=C/itemsVector[i].weight;
            C=0;
            selectedItemsVector.push_back(itemsVector[i]);
        }
        i++;
    }
    cout<<"***********************Selected Items*****************"<<endl;
    for(Item item:selectedItemsVector){
        cout<<"(name="<<item.name<<",price="<<item.price<<",weight="<<item.weight<<",portion taken="<<item.portionTaken<<endl;
    }
    cout<<"Total profit:"<<profit<<endl;
}


int main(){
    cout<<"Enter the number of items"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the capacity"<<endl;
    int C;
    cin>>C;

    vector <Item> itemsVector;

    cout<<"Enter the items info (name,price,weight)"<<endl;
    for(int i=1;i<=n;i++){
        string name;
        float price,weight;
        cin>>name>>price>>weight;
        Item item(name,price,weight);
        itemsVector.push_back(item);
    }

    cout<<"You entered the following items"<<endl;
    for(Item item:itemsVector){
        cout<<"(name="<<item.name<<",price="<<item.price<<",weight="<<item.weight<<",priceByWeight="<<item.priceByWeight<<endl;
    }

    fractionalKnapsack(itemsVector,n,C);
    return 0;
}
/*
7 15
item1 10 2
item2 5 3
item3 15 5
item4 7 7
item5 6 1
item6 18 4
item7 3 1
*/

