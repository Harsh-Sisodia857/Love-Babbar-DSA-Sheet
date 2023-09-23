#include<bits/stdc++.h>
using namespace std;

int checkForEmptyString(string skill){
    int count = 0;
    for (int i = 0; i < skill.size(); i++){
        if(skill[i] == "")
            count++;
    }
    return count;
}

vector<vector<string>> newRequirement(string skill[],vector<string> person){
    int size = person.size();
    int size2 = skill.size();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size2; j++){
            
        }
    }
}

    int
    f(int idx, int count, string skill[], vector<vector<string>> person)
{
    // base case
    if(idx == 0){
        int s = checkForEmptyString(skill);
        if (s == 0)
            return count;
        if(skillContains(person[idx])){
           skill = newRequirement(skill, person[idx]);
           s = checkForEmptyString(skill);
           if(s == 0)
               return count;
           return 0;
        }
        return 0;
    }

    int l = 0;
    if(skillContains(person[idx])){
        skill = newRequirement(skill, person[idx]);
        l = f(idx + 1, count + 1, skill, person);
    }
    int r = f(idx + 1, count, skill, person);
    return min(l, r);
}

int main(){
    string skillSet[] = {"java", "nodejs", "react", "c++"};
    vector<vector<string>> person = {{"java"}, {"nodejs,react"}, {"c++"}, {"java", "c++"}};
    return f(0,0, skillSet, person);
    return 0;
  }