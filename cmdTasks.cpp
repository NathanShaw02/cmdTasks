#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printVector(vector<string>& vect){

    for(int i = 0; i<vect.size(); i++){
        cout<<i<<": "<<vect[i]<<endl;
    }

}

void importTasks(vector<string>& taskVector){
    //use task pointer to shove the tasks straight into the vector 8)
    ifstream myFile("tasksDB.txt");
    string task;

    while(getline(myFile,task)){
        taskVector.push_back(task);
    }

    myFile.close();
}

void exportTasks(vector<string>& taskVector, int elementToBeLast){

    string lastAppend = taskVector[elementToBeLast];

    ofstream myFile("tasksDB.txt", ios::out);

    for(int i = 0; i<taskVector.size(); i++){
        if(i==elementToBeLast){
            continue;
        }else{
            myFile<<taskVector[i]<<endl;
        }
    }
    //append element excluded
    myFile<<taskVector[elementToBeLast]<<endl;


    myFile.close();

}


int main(int argc, char* argv[]){ //main natively processes cmd line stuff into [numberOfArgs,argsPassed]

    //setup for application, could do this for only rm task and get task but I think this inefficiency is fine
    vector<string> taskList;
    importTasks(taskList);

    if(argc > 3){
        //repurpose this code at the end when you catch exception that no valid commands were passed
        cout<<"Parameters:\n -g / get_tasks,\n -a / add_task <taskText>,\n -r / rm_task <taskNum>"<<endl;

        return -1;
    }else if(argc == 1){
    
        cout<<"No args :...C      do:"<<endl;
        cout<<"Parameters:\n -g / get_tasks,\n -a / add_task <taskText>,\n -r / rm_task <taskNum>"<<endl;
        return -2;
    
    }else{
        string mainArg = argv[1]; //args start at index 1 :/

        if(mainArg=="get_tasks"||mainArg=="-g"){//completed
            printVector(taskList);

        }else if(mainArg=="add_tasks"||mainArg=="-a"){//TO DO
            string taskText;
            //use stringbuilder to add all the rest of the arguments 


        }else if(mainArg=="rm_task"||mainArg=="-r"){//completed
            int taskNum = stoi(argv[2]);

            if(taskNum>(taskList.size()-1)||taskNum<0){ //validation for if task index invalid
                cout<<"Task index not found";
            }else{
                //swaps and removes last line - DOES however change task order so need to compensate in write
                swap(taskList[taskNum],taskList[taskList.size()-1]);

                //append to completed tasks file
                ofstream completedTasks("completedTasks.txt",ios::app);
                    completedTasks<<taskList[taskList.size()-1]<<endl;

                //remove from vec
                taskList.pop_back();

                //write to file
                exportTasks(taskList, taskNum);

                cout<<"Task Removed!"<<endl;
            }

            //remove task number
                //add to completed tasks txt

        }
    }



    return 0;
}


/*

To:Do

Change from vector storage to array



*/