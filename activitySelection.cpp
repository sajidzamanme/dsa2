#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
    string name;
    int startTime;
    int endTime;
    Activity(string name,int startTime,int endTime){
        this->name=name;
        this->startTime=startTime;
        this->endTime=endTime;
    }
};

bool myComparator(Activity a, Activity b){
    if(a.endTime<b.endTime){
        return true;
    }else{
        return false;
    }
}

vector<Activity> ActivitySelection(vector <Activity> activitiesVector){
    sort(activitiesVector.begin(),activitiesVector.end(),myComparator);
//    cout<<"Activities vector after sorting is"<<endl;
//    for(Activity a:activitiesVector){
//        cout<<"("<<a.name<<","<<a.startTime<<","<<a.endTime<<")"<<endl;
//    }
   vector <Activity> selectedActivities;
   int k = 0;
   selectedActivities.push_back(activitiesVector[k]);

   for(int i=1;i<=activitiesVector.size()-1;i++){
        if(activitiesVector[i].startTime<activitiesVector[k].endTime){
            // do nothing - as the activities are overlapping
        }else{
            k=i;
            selectedActivities.push_back(activitiesVector[k]);
        }
   }
    cout<<"Selected activities:"<<endl;
    for(Activity a:selectedActivities){
        cout<<"("<<a.name<<","<<a.startTime<<","<<a.endTime<<")"<<endl;
    }
    return selectedActivities;
}

int main(){
    int n;
    cout<<"Enter the total number of activities"<<endl;
    cin>>n;
    vector <Activity> activitiesVector;
    cout<<"Enter the activity details"<<endl;
    for(int i=1;i<=n;i++){
        string name;
        int startTime;
        int endTime;
        cin>>name>>startTime>>endTime;

        Activity a (name,startTime,endTime);
        activitiesVector.push_back(a);
    }

    for(Activity a:activitiesVector){
        cout<<"("<<a.name<<","<<a.startTime<<","<<a.endTime<<")"<<endl;
    }
    ActivitySelection(activitiesVector);
    return 0;
}

/*
5
Incredibles 6 9
Matrix 1 3
Avengers 5 7
Batman 8 10
Superman 2 4
*/
