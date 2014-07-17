It's for C Programming.

gcc -o arg_va arg_va.c

/* If the headers are located in some other (non-standard) location you would include like standard headers:
use the -I (uppercase i ) flag to include the directory containing them. */
gcc -I/path/to/directory/containing/header_name -o myoutputfile myoutputfile.c
gcc -include /path/to/directory/containing/header_name/header_name.h -o myoutputfile myoutputfile.c

SetUp Environment :
	https://github.com/
		https://help.github.com/articles/set-up-git - Install GitHub for Windows
	http://www.mingw.org/wiki/Getting_Started
		You must add C:\MinGW\bin; to your user PATH environment variable manually. 
		You can permanently add C:\MinGW\bin; to your PATH by following the 
		instructions in the "Environment Settings" section on the MinGW Getting Started page.
		
	Windows Eclipse
		installing 64 bit JVM from http://www.java.com/en/download/manual.jsp
		http://eclipse.org/egit/download/ - Eclipse Download

/* create a new branch named "feature_x" and switch to it using *
git checkout -b feature_x

/* switch back to master */
git checkout master

/* and delete the branch again */
git branch -d feature_x

/* a branch is not available to others unless you push the branch to your remote repository */
git push origin <branch>

/* to update your local repository to the newest commit, execute */
git pull 

/* in your working directory to fetch and merge remote changes.
to merge another branch into your active branch (e.g. master), use */
git merge <branch>

/* it's recommended to create tags for software releases. */
git tag 1.0.0 1b2e1d63ff

git log
/* To see only the commits of a certain author: */
git log --author=bob
/* To see a very compressed log where each commit is one line */
git log --pretty=oneline
git log --graph --oneline --decorate --all
/* See only which files have changed:  */
git log --name-status
git log --help

git checkout -- <filename>
/* If you instead want to drop all your local changes and commits, 
fetch the latest history from the server and point your local master branch at it like this */
git fetch origin
git reset --hard origin/master

/* use colorful git output */
git config color.ui true
/* show log on just one line per commit */
git config format.pretty oneline

/* use interactive adding */
git add -i
