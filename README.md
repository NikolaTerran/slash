# slash
Super_Lol_Awesome_SHell

by TL

Features:
	Forks and executes commands!
	Disregard C^
	Parses multiple commands on one line!
	Can Redirect using >, <!
	Can get pipes to work
	It will give you a syntax error warning if you try to do wierd stuff with redirect
	Shows you input in the beginning

Attempted:
	The following did not end up working, but have been left in the code, commented out.
	A nethack looking interface
	Cannot Guarantee to regrow hair!
	Cannot summon a winged unicorn for fast & magical transit!

Bugs:
	Input should be no longer than 256 characters.
	
Files & Function Headers:
parse_args.c
	Break inputs into args
	Inputs:  char *input
	Returns: char ** comrade

exeorder.c
	Take in arguments and determine its type
	Inputs: char ** comrade
	returns: 0
	
operation.c
	make ; <>| operations
	inputs: char ** comrade
	returns: 0
	
detect_operators.c
	check is there a ; <> or | in the args
	inputs: comrade
	returns: 0
	
main.c
	the main.

slash.h
	function header.
