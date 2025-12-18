Q1) On a pas le droit d'utiliser le printf, on a donc utiliser la fonction write, avec les arguments
associés nécessaire à son bon fonctionnement

Q2a) On utilise la fonction read(), qui nous permet de lire ce que l'utilisateur écrit sur la clavier.

Q2b) On utilise la fonction execlp() qui nous permet d'interpreter un programme connu qui pourrait
être taper par l'utilisateur.
Petite subtilité on doit enlever le /n qui est par défaut mis quand l'utilisateur appuie sur entrée
et qui fausse l'interprétation.

Q2c) Avant une fois qu'on mettait un programme par exemple ls, il l'exécuter puis arrêter
la simulation du shell car devenait le
programme. Donc maintenant on créait un fils avec fork() qui va éxécuter à la place le programme demandé 
par l'utilisateur puis va être tuer et redonner la main au père Ce que permet de ne pas sortir du shell.

Q3) On doit pouvoir sortir du shell à l'aide d'un Ctrl+D ou d'un exit. Ce qui est donc réalisé
dans notre programme à l'aide de condition
et d'un break qui nous permet de sortir de la boucle une fois que crtl D ou exit et écrit par
l'utilisateur dans le terminal.

Q4)
L’objectif de cette question est d’afficher, dans le prompt, le code de retour ou le signal associé à la commande exécutée précédemment.
<img width="1267" height="663" alt="image" src="https://github.com/user-attachments/assets/45aaaddf-3907-4d86-aac1-57857e9e9745" />

Q5)
Afficher le temps d’exécution de la commande précédente dans le prompt.
<img width="862" height="611" alt="image" src="https://github.com/user-attachments/assets/05256b61-b20b-46fc-b4f2-f3f879a7f22b" />

Q6)
Permettre l’exécution de commandes comportant des arguments
<img width="1297" height="673" alt="image" src="https://github.com/user-attachments/assets/9bc94527-0d4d-48d0-8695-a7c85cc4a005" />









Q7)

Voici ce qu'on observe dans la console, et c'est bien ce qui est attendu
<img width="967" height="547" alt="image" src="https://github.com/user-attachments/assets/8a225328-7cd7-4e44-9e97-e0ac26c8dde2" />
On a bien le fichier qui est crée 
<img width="1583" height="693" alt="image" src="https://github.com/user-attachments/assets/878f1b78-d40f-400a-b41c-76991ed05659" />

