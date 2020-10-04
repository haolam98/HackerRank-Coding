/*
Emma is playing a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus  1 or 2. She must avoid the thunderheads. Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. It is always possible to win the game.

For each game, Emma will get an array of clouds numbered  if they are safe or  if they must be avoided. For example, c= {0 1 0 0 0 1 0} indexed from 0 to 6 . The number on each cloud is its index in the list so she must avoid the clouds at indexes 1 and 5. She could follow the following two paths:  0-2-4-6 or 0-2-3-4-6 . The first path takes 3 jumps while the second takes 4.

Ex: 

    c = [0 0 1 0 0 1 0] => output = 4
*/

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) 
{
    int size = c.size();
    if (size ==2)
    {
        return 1;
    }
    int index =0;
    int step=0;
    while (index !=size-1)
    {
        if (c[index+2]==0)
        {
            index+=2; // jump 2 
        }
        else
        {
            index+=1; // jump 1 only
        }
        step++;

    }
    return step;
}
