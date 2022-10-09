/*
Marc loves cupcakes, but he also likes to stay fit. 
Each cupcake has a calorie count, and Marc can walk a distance to expend those calories. 
If Marc has eaten  cupcakes so far, after eating a cupcake with  calories he must walk at least  miles to maintain his weight.

Example
If he eats the cupcakes in the order shown, the miles he will need to walk are . 
This is not the minimum, though, so we need to test other orders of consumption. In this case, our minimum miles is calculated as .

Given the individual calorie counts for each of the cupcakes, determine the minimum number of miles Marc must walk to maintain his weight. 
Note that he can eat the cupcakes in any order.

Function Description
Complete the marcsCakewalk function in the editor below.

marcsCakewalk has the following parameter(s):

int calorie[n]: the calorie counts for each cupcake

Returns
long: the minimum miles necessary

Input Format
The first line contains an integer , the number of cupcakes in .
The second line contains  space-separated integers, .

Sample Input 0
3
1 3 2

Sample Output 0
11

Sample Input 1
4
7 4 9 6

Sample Output 1
79
*/

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

function marcsCakewalk(calorie) {
    // Write your code here
    let maxValue = 0;
    calorie.sort(function(a,b){return b-a});
    for(let i=0; i<calorie.length; i++){
        maxValue += calorie[i] * Math.pow(2, i);
    }
    return maxValue;
}
