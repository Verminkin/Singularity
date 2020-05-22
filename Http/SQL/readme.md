<html>

<h1># HTTP Server</h1>

<h2>ajout du serveur SQL</h2>
<body>
<br>

<h3>Welcome</h3>



Documentation
MariaDB (MySQL) server.
Documentation: https://www.hpc.iastate.edu/guides/containers/mysql-server
<br>
## Setup:
<br>
<h3>BUILD</h3>
commande pour le le serveur à rentrer successivement lire tout le read me pour bien configurer le serveur
singularity build --sandbox mysql.sif mySql.def
<br>
```<br>
<h3>BIND et instanciation</h3>
singularity instance start  -B ${HOME} \
-B ${PWD}/mysql/var/lib/mysql/:/var/lib/mysql \
-B ${PWD}/mysql/run/mysqld:/run/mysqld \
./mysql.sif mySql
<br>
<h3>LANCEMENT</h3>
singularity run instance://mysql create_remote_admin_user.sh
```<br>

<br>


<br>### la commande help marche comme ce readme:
<br>

```
$ singularity run-help mysql.sif
ou plus généralement
$ singularity run-help 'nom de votre conteneur'.sif
```
la commande help se lance aussi avec cette commande
```
$ ./'nom de votre conteneur'.sif
```




   ### Lancement du serveur:
 Avant de start le conteneur merci de remplir my.cnf et mysqlrootp

```
 my.cnf example:

[mysqld]
innodb_use_native_aio=0
init-file=${HOME}/.mysqlrootpw
user            = root
pid-file        = /var/run/mysqld/mysqld.pid
socket          = /var/run/mysqld/mysqld.sock
port            = 3306
basedir         = /usr
datadir         = /var/lib/mysql
tmpdir          = /tmp
bind-address    = 127.0.0.1
[client]
user=root
password='kek'
explicit_defaults_for_timestamp = 1
port             = %PORT%                              # default 3306
socket           = %SOCKET%                            # Use mysqld.sock on Ubuntu, conflicts with AppArmor otherwise

```
<br> mysqlrootpw example :

```
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('kek');
```
<br>Pour cette partie il faut bind le dossier www au conteneur :
    
    ```
    singularity instance start  -B ${HOME} \
    -B ${PWD}/mysql/var/lib/mysql/:/var/lib/mysql \
    -B ${PWD}/mysql/run/mysqld:/run/mysqld \
    ./mySql.sif mySql
    ```
    
 puis cette commande lance le serveur
 
 ```
singularity run instance://mysql create_remote_admin_user.sh
```



lancer une page web à l'adresse d
http://localhost:3306
```
ou:
 rentrer en ligne de commande  dans votre hote (pas le conteneur)
 ```
-> mysql -h 127.0.0.1
```

<br>## Arreter le serveur :


```
$ singularity instance stop mysql
```


</body>
</html>