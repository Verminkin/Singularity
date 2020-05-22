<html>

<h1># HTTP Server</h1>

<h2>Création d'un serveur web simple</h2>
<body>
<br>

<h3>Welcome</h3>


<br>
<br>
## Setup:
<br>
commande pour le dossier
<br>

```
$ mkdir ~/www
$ cd ~/www/
```

<br>

ensuite soit créer le conteneur via la recette (requiere le sudo) sinon le pull via le singularity hub ou docker (link):
<br>
```<br>
$ singularity build http.sif http.def
```


<br>### la commande help marche comme ce readme:
<br>

```
$ singularity run-help http.sif
```
<br>ou plus généralement
```
$ singularity run-help 'nom de votre conteneur'.sif
```
<br>la commande help se lance aussi avec cette commande
<br>```
$ ./'nom de votre conteneur'.sif
<br>```

<br>

<br>## Dans cette partie il ne faut la faire que si le build n'a pas créer les fichier suivant htdocs/logs et index.html
qui est votre fichier qui va s'ouvrir sur 

```le localhost:8080:```

<br>toute les info lié au serveur son enregistré dans le log:

<br>Création des branchements:

<br>

```
$ mkdir -p httpd/{htdocs,logs}
```

<br>

<br>Tous file index.hmtl peut etre mis de base il est créer mais vide (possibilité que le serveur ne fonctionne pas
quand il est vide) remplacer le des que possible
<br>```
$ touch httpd/htdocs/index.html
<p>
    <br>Le répertoire doit ressembler à ceci:
    <br>
    
    ```
    ~/www/
        |-- www/
        | `-- htdocs/index.html
        | `-- logs/
        ```


    <br>

 <br>### Lancement du serveur:

 Pour cette partie il faut bind le dossier www au conteneur :

 ```
 $ singularity instance start -B www/:/srv/www/ 'nom du conteneur'.sif 'nom de l'instance '
en modifiant le code tu pourais avoir plusieurs instance il suffit de changer le port dans le fichier.def sinon
    le nom de l'instance est libre
  ```

    <br>

lancer une page web à l'adresse d
```
    <br>http://localhost:8080
```
ou:
```
 $ w3m http://localhost:8080
```


## Arreter le serveur :


```
$ singularity instance stop www
```



</body>
</html>