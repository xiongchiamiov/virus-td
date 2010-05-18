Virus-td is a tower defense game, created for an introductory AI course and a
graphics course at Cal Poly. This, specifically, is a git mirror of the
canonical Subversion repository.

# Building and Running the Game

## Linux

Only one of our developers is using Linux primarily, and he cba to create a
proper makefile. As a result, you will have to rebuild all the files each time
you make a change.

The line that he uses is `touch virus-td && make && ./virus-td`.

# Contributing using Git

Git is pretty awesome, and you can use it to contribute to this project.

## Checking out the project

	git clone git://github.com/xiongchiamiov/virus-td.git
	cd virus-td
	git svn init --prefix=svn/ svn+ssh://fileserverness.ath.cx/serv/svn/virus-td/
	git svn fetch
	git svn rebase

## Making changes

	git pull
	git svn rebase
	[hack hack hack]
	git add .
	git commit -m 'a super-helpful message'
	git svn dcommit
	git push
