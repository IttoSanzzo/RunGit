<h1 align="center">RunGit</h1>
<p align="center"><img src="https://i.imgur.com/ogINTV4.png"></p>

---

-   Just a simple program to run commits and pushes faster, and without the need to write various commands.
-   I can be compiled using `make`:

```Bash
make
```

-   Once compiled, you can add the `rungit` program to your /bin/ directory, to be able to use it anywhere:

```Bash
cp ./rungit /bin/
```

-   Then, you can use it by running the command bellow inside a repository directory:

```Bash
rungit <commit  message>
```

-   In which, the `<commit massage>` should be the commit name you want for the push.
-   Then, it will add all the files in the current directory, and recursively, commit then with the given message, and push then to github, all in one command.
-   But it's good to keep in mind that, it's as dangerous as conveniente, so be cautious when using it.
