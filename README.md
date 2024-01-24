# AP_Project Ex1
### link to repository
https://github.com/Shiranle07/AP_Project.git

## Compile And Run The Code
#### 1. Prerequisites: Clone all the cpp and header files from the repository.
#### 2. Compile the code
   * Make sure you are in the right path, where you cloned the erpository.
   * Open the terminal and run:
   
```Terminal
g++ ./src/App.cpp ./src/BloomFilter.cpp ./src/CheckUrlCommand.cpp ./src/InsertUrlCommand.cpp ./src/HashOne.cpp ./src/HashTwo.cpp ./src/InputValidation.cpp ./src/main.cpp -o ./build/AP_exe1
```

#### 3. Run the code

   Open the terminal and run:
```Terminal
./build/AP_exe1
```
## Work Flow:
First, we read the task in its entirety together and checked that we correctly understood what was assigned to us.
Together we came up with ideas for implementation in a general way and divided between us the general tasks that we added to JIRA.
The first task was to write TDD for the basic tasks of the project and on top of that we wrote the various classes.
Towards the end of writing the code, we made sure that the logical flow worked and that everything looked normal and we made corrections if needed.
At this stage we conducted the TDD tests and fixed all the bugs we discovered.
During the work, we made sure to use different branches throughout the work while updating the GIT. When we were sure of a certain version, we uploaded it to the main branch.

In the next step, we created a Docker File and from it we built a container that contains all the desired dependencies in order to run the project. We created another Workflow in GIT whose goal is to produce an updated Docker Image for each new version of the code and upload it to GitHub

## Refactors:
While implementing the code, we used a dictionary in order to make the commands we used more flexible, and to make the code more flexible to changes. For example, by adding HASH functions, we will only have to update the dictionary.







