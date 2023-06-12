# minimum_cost
Explanation of the getMinCost function
TL;DR
The getMinCost function takes two vectors of integers representing the IDs of crews and jobs, and returns the minimum cost of assigning each crew to a job, where the cost is the absolute difference between the crew ID and job ID.
Explanation
The getMinCost function implements the Hungarian algorithm to solve the assignment problem. The assignment problem is a combinatorial optimization problem that involves assigning a number of resources to an equal number of activities, where each resource has a cost for each activity. The goal is to find the assignment that minimizes the total cost.
The Hungarian algorithm is a polynomial-time algorithm that solves the assignment problem by constructing a dual problem and finding the optimal solution to the dual problem. The dual problem is a linear programming problem that can be solved using the simplex algorithm.
The getMinCost function first creates a cost matrix that represents the cost of assigning each crew to each job. The cost is calculated as the absolute difference between the crew ID and job ID. It then initializes the dual variables u and v and the auxiliary variables p and way. It then iteratively improves the dual solution until it is optimal.
The function returns the negation of the optimal dual solution, which is equal to the minimum cost of assigning each crew to a job.
Possible bugs

If the crew_id or job_id vectors are empty, the function will throw an error.
If the crew_id or job_id vectors have duplicate IDs, the function may not return the correct minimum cost.

Possible improvements

Add input validation to ensure that the crew_id and job_id vectors have the same length.
Use a more efficient implementation of the Hungarian algorithm, such as the Kuhn-Munkres algorithm.
Add an optional argument to allow the user to specify the cost function.

References

Assignment problem
Hungarian algorithm
