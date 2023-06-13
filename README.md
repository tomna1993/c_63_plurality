# c_63_plurality

## DESCRIPTION

For this program, you’ll implement a program that runs a plurality election, per the below.

```bash
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

### BACKGROUND

Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

### IMPLEMENTATION DETAILS

- create `plurality.c`

- Define `MAX` to `9` as a constant (equal to 9) that can be used throughout the program. Here, it represents the maximum number of candidates an election can have.

- Define a `struct` called `candidate`. Each candidate has two fields: a `string` called `name` representing the candidate’s name, and an `int` called `votes` representing the number of votes the candidate has.

- Use a variable `candidate_count` to represent the number of candidates in the election.

- Ask the user to type in the number of voters. Then, the program lets every voter type in a vote, calling the `vote` function on each candidate voted for.
  - `vote` takes a single argument, a `string` called `name`, representing the name of the candidate who was voted for.
  - If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The vote function in this case should return `true` to indicate a successful ballot.
  - If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote function should return `false` to indicate an invalid ballot.
  - You may assume that no two candidates will have the same name.

- Finally, `main` makes a call to the `print_winner` function to print out the winner (or winners) of the election.
  - The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
  - It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.

Your program should behave per the examples below.

``` bash
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice

$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice

$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```
