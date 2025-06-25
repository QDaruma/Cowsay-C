# 🐄 Projet Cowsay

Une collection de programmes en Bash et C mettant en scène des vaches ASCII pour l'apprentissage et le divertissement.

## 📋 Description

Ce projet propose une série d'applications ludiques utilisant le célèbre programme `cowsay` et des vaches ASCII personnalisées. Il est divisé en deux parties principales : des scripts Bash éducatifs et des programmes C plus avancés avec des fonctionnalités interactives.

## 🗂️ Structure du Projet

```
├── Bash/                    # Scripts éducatifs en Bash
│   ├── cow_kindergarten.sh  # Comptage 1-9 (niveau maternelle)
│   ├── cowprimaryschool.sh  # Comptage jusqu'à N (niveau primaire)
│   ├── cowhighschool.sh     # Carrés parfaits (niveau lycée)
│   ├── cowcollege.sh        # Suite de Fibonacci (niveau université)
│   ├── cowuniversity.sh     # Nombres premiers (niveau master)
│   ├── crazycow.sh          # Jeu de devinettes
│   └── smartcow.sh          # Calculatrice simple
└── C/                       # Programmes avancés en C
    ├── newcow.c            # Vache personnalisable avec options
    ├── reading_cow.c       # Lecture animée de fichiers
    └── tamagochi_cow.c     # Jeu Tamagotchi avec vache
```

## 🎓 Scripts Bash - Série Éducative

### Scripts Mathématiques par Niveau

- **`cow_kindergarten.sh`** - Compte de 1 à 9
- **`cowprimaryschool.sh <N>`** - Compte de 1 à N
- **`cowhighschool.sh <N>`** - Affiche les carrés de 1 à N²
- **`cowcollege.sh <N>`** - Génère les N premiers nombres de Fibonacci
- **`cowuniversity.sh <N>`** - Trouve tous les nombres premiers jusqu'à N

### Scripts Interactifs

- **`crazycow.sh`** - Jeu de devinettes (nombre entre 1 et 100)
- **`smartcow.sh <expression>`** - Calculatrice qui évalue une expression mathématique

## 💻 Programmes C - Fonctionnalités Avancées

### `newcow.c` - Vache Personnalisable
Programme principal avec de nombreuses options de customisation :

**Options disponibles :**
- `-e<yeux>` : Change les yeux de la vache (ex: `-eoo`, `-e><`)
- `-t<langue>` : Change la langue de la vache (ex: `-tUU`)
- `-cpu` : Transforme la vache en ordinateur ASCII
- `-rgb` : Active l'affichage multicolore

**Exemples d'utilisation :**
```bash
./newcow "Hello World!"
./newcow -eXX -tUU "Vache fatiguée"
./newcow -cpu -rgb "Vache ordinateur colorée"
```

### `reading_cow.c` - Lecteur Animé
Lit un fichier caractère par caractère avec animation :
```bash
./reading_cow fichier.txt    # Lit un fichier
echo "Hello" | ./reading_cow # Lit depuis stdin
```

### `tamagochi_cow.c` - Jeu Tamagotchi
Jeu interactif où vous devez nourrir votre vache virtuelle :

**Fonctionnalités :**
- Deux modes : Vache classique ou Homer Simpson
- Système de santé et de stock alimentaire
- Événements aléatoires (nourriture qui pourrit/se trouve)
- Score basé sur la survie
- États visuels différents selon la santé

## 🚀 Installation et Utilisation

### Prérequis
- **Pour Bash :** `cowsay` installé sur le système
- **Pour C :** Compilateur GCC

### Installation de cowsay
```bash
# Ubuntu/Debian
sudo apt-get install cowsay

# macOS avec Homebrew
brew install cowsay

# Arch Linux
sudo pacman -S cowsay
```

### Compilation des programmes C
```bash
cd C/
gcc -o newcow newcow.c
gcc -o reading_cow reading_cow.c
gcc -o tamagochi_cow tamagochi_cow.c
```

### Rendre les scripts Bash exécutables
```bash
cd Bash/
chmod +x *.sh
```

## 🎮 Exemples d'Utilisation

### Scripts Bash
```bash
# Séquences mathématiques
./cowcollege.sh 10        # 10 premiers nombres de Fibonacci
./cowuniversity.sh 20     # Nombres premiers jusqu'à 20

# Jeux
./crazycow.sh            # Jeu de devinettes
./smartcow.sh "2+2*3"    # Calcul : 2+2*3
```

### Programmes C
```bash
# Vache personnalisée
./newcow -eoo -tUU "Vache heureuse"
./newcow -cpu -rgb "Ordinateur coloré"

# Lecture animée
./reading_cow poeme.txt

# Tamagotchi
./tamagochi_cow
```

## 🎨 Fonctionnalités Techniques

### Scripts Bash
- Utilisation de boucles `for` et `while`
- Fonctions personnalisées
- Gestion des arguments de ligne de commande
- Génération de nombres aléatoires
- Algorithmes mathématiques (Fibonacci, nombres premiers)

### Programmes C
- Gestion dynamique de la mémoire
- Codes couleur ANSI pour l'affichage
- Manipulation de chaînes de caractères
- Lecture de fichiers et stdin
- Génération de nombres aléatoires
- Interface utilisateur en mode texte

## 🎯 Objectifs Pédagogiques

Ce projet est conçu pour :
- **Apprendre la programmation Bash** avec des exemples progressifs
- **Découvrir la programmation C** avec des projets amusants
- **Comprendre les algorithmes** mathématiques de base
- **Développer des interfaces** en mode texte
- **S'amuser** tout en programmant !


## 👥 Crédits

**Développé par :** Chamberlan Quentin en 2022
