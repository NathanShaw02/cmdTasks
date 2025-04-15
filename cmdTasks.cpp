#include <vector>
#include <iostream>
#include <string>

using namespace std;

void printVector(vector<string>& vect){

    for(int i = 0; i<vect.size(); i++){
        cout<<i<<": "<<vect[i]<<endl;
    }

}

void importTasks(vector<string>& taskVector){
    //use task pointer to shove the tasks straight into the vector 8)


}


int main(int argc, char* argv[]){ //main natively processes cmd line stuff into [numberOfArgs,argsPassed]

    vector<string> myVect = {"a","b","c"};

    printVector(myVect);

    if(argc > 3){
        //repurpose this code at the end when you catch exception that no valid commands were passed
        cout<<"Parameters:\n -g / get_tasks,\n -a / add_task <taskText>,\n -r / rm_task <taskNum>"<<endl;

        return -1;
    }else{
        string mainArg = argv[1]; //args start at index 1 :/

        if(mainArg=="get_tasks"||mainArg=="-g"){
            //add number to task that you print
                //task numbers not stored in task as part of it, just added for use

        }else if(mainArg=="add_tasks"||mainArg=="-a"){
            string taskText;
            //use stringbuilder to add all the rest of the arguments 


        }else if(mainArg=="rm_task"||mainArg=="-r"){
            int taskNum = stoi(argv[2]);

            //remove task number
                //add to completed tasks txt

        }
    }



    return 0;
}