# Contributing Guidelines
1. Everyone is welcome to contribute.
1. Whole and sole purpose of this project is to learn by collaborating.
1. Each solution that is submitted will be tested on the corresponding judge and will not be merged if not accepted.
1. Multiple solutions to a single problem are welcome as long as they use different approach.
1. Correct folder heirarchy and naming convention to be followed:
	1. In project directory there should be a directory[ies] by the name of corresponding judge. For ex. HackerRank, CodeChef, etc.
	1. In that directory there should be a directory[ies] by the problem identifier i.e. something that can be used to differentiate the problem easily. It can be different for different judges:
		1. CodeChef assignes problem code to each problem. Hence, for CodeChef, that will be the identifier.
		1. Since, there is no such problem code on HackerRank, the URL slug of the problem should be used there.
		1. Since different judges handle this differently, this one can be managed on case-to-case basis.
		1. All the problems in a particular judge should follow the same naming convention.
		1. Best method to know about naming convention of the problem directory is to check existing solutions for the corresponding judge.
		1. If you are posting a solution for a judge for which there is no existing solution, you are welcome to suggest your own naming convention to identify the problem directory.
	1. Inside the problem directory, there should be[if doesn't exist already] a markdown file named "Resources and References" in which there should be the link to the problem and optionally, link[s] to solution videos/articles or editorials.
	1. In the problem directory itself, there should be[if doesn't exist already] a folder by the name "Solutions".
	1. In the "Solutions" directory, there should be a directory whose name will be the language you are using. For ex. let's say we created a directory name "Python".
	1. In the "Python" directory, the solution file should be placed.
	1. Name of the solution file should be same as the problem identifier[point 5.2] optionally with a suffix that represents the algorithm or the problem solving method. For ex, if the problem identifier is "PROB" and you are using Bitmasking to solve it, then you can name it either "PROB" itself or something like "PROB_btmsk".
	1. Extension of the solution file should be something that is commonly used for files written in your chosen language. For ex. ".py" for Python.
1. Multiple solutions per PR are not recommended.
