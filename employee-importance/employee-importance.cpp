/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int importance = 0;
        Employee* emp ;
        for(auto employee : employees)
        {
        
            if(employee->id == id)
            {
                emp = employee;
            }
                
        }
        
        dfs(emp,importance,employees);
        

        
        return importance;
    }
    
    void dfs(Employee* emp,int& importance,vector<Employee*>& employees)
    {
        importance += emp->importance;
        
        for (auto subordinateID: emp->subordinates)
        {
        	for (auto subordinate: employees)
        	{
        		if (subordinate->id == subordinateID) {
                    
                    dfs(subordinate,importance,employees);
                }
        	}
        }

    }
};