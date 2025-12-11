Q1) On a pas le droit d'utiliser le printf, on a donc utiliser la fonction write, avec les arguments associés nécessaire à son bon fonctionnement
Q2a) On utilise la fonction read(), qui nous permet de lire ce que l'utilisateur écrit sur la clavier.
Q2b) On utilise la fonction execlp() qui nous permet d'interpreter un programme connu qui pourrait être taper par l'utilisateur.
Petite subtilité on doit enlever le /n qui est par défaut mis quand l'utilisateur appuie sur entrée et qui fausse l'interprétation.
Q2c) Avant une fois qu'on mettait un programme par exemple ls, il l'exécuter puis arrêter la simulation du shell car devenait le
programme. Donc maintenant on créait un fils avec fork() qui va éxécuter à la place le programme demandé 
par l'utilisateur puis va être tuer et redonner la main au père Ce que permet de ne pas sortir du shell.
Q3) On doit pouvoir sortir du shell à l'aide d'un Ctrl+D ou d'un exit. Ce qui est donc réalisé dans notre programme à l'aide de condition
et d'un break qui nous permet de sortir de la boucle une fois que crtl D ou exit et écrit par l'utilisateur dans le terminal.
