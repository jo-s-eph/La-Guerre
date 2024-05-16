<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![MIT License][license-shield]][license-url]




<!-- PROJECT LOGO -->
<br />
<div align="center">

  <h3 align="center">La Guerre - Projet C++</h3>

  <p align="center">
    Implémentation d'un jeu de plateau en C++ en utilisant la programmation orienté objet.
    <br />
    <br />
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Sommaire</summary>
  <ol>
    <li>
      <a href="#about-the-project">À propos du projet</a>
    </li>
    <li>
      <a href="#getting-started">Démarrer</a>
      <ul>
        <li><a href="#prerequisites">Prérequis</a></li>
        <li><a href="#installation">Installer et jouer</a></li>
      </ul>
    </li>
    <li><a href="#usage">Déroulement de la partie</a></li>
    <li><a href="#license">Licence</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## À propos du projet

[![Product Name Screen Shot][product-screenshot]]()

"La guerre !" est un jeu de stratégie au tour par tour où deux équipes, les Bleus et les Rouges, s'affrontent sur un plateau carré de 20x20 cases. Chaque équipe dispose de différents types de pions : château, seigneur, guerrier, et paysan, chacun ayant des fonctions spécifiques.

Types de Pions:
* Château : produit des pions et de l'or, ne peut ni se déplacer ni attaquer.
* Seigneur : peut se déplacer, attaquer, ou se transformer en château.
* Guerrier : se déplace et attaque.
* Paysan : se déplace ou produit des ressources.

Le but de ce projet est d'intégrer ce jeu de plateau en C++ en utilisant une programmation orienté objet (notion d'héritage, fonctions virtuelles, etc..).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Démarrer

Pour jouer au jeu : 

### Prérequis

* C++20

### Installer et jouer

Pour pouvoir jouer au jeu, suivre les instructions suivantes : 

2. Cloner le repo
   ```sh
   git clone https://github.com/jo-s-eph/La-Guerre.git
   ```
3. Compiler
   ```sh
   make
   ```
4. Exécuter
   ```sh
   ./jeu.exe
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Déroulement de la partie : 

Chaque joueur commence avec un château, un paysan, et une quantité d'or égale.
Les joueurs jouent chacun leur tour en donnant des ordres à leurs pions. Un seul ordre par pion par tour.

### Exemples d'ordres :
- Transforme-toi en château
- Déplace-toi vers cette case
- Construis un pion
- Déplace-toi puis attaque ce pion
- Amasse des ressources

### Fin de la Partie

Le jeu se termine lorsqu'un joueur perd tous ses châteaux.

### Actions Possibles
- Ne fait rien
- Se déplace
- Se déplace et attaque un autre pion
- Construit un pion sur une case adjacente
- Amasse des ressources
- Se transforme en château

### Caractéristiques des Pions

| Type     | Puiss. | PV ini | Dépl. | Prod. | Coût | Action spéciale                |
|----------|--------|--------|-------|-------|------|--------------------------------|
| Château  | 0      | 20     | 0     | 2     | 15   | Construit des pions mobiles    |
| Guerrier | 5      | 10     | 3     | 0     | 10   |                                |
| Paysan   | 0      | 1      | 2     | 5     | 20   | Produit de l’or                |
| Seigneur | 3      | 5      | 1     | 0     | 10   | Se transforme en château       |


**Dépl. (déplacement)** : Nombre maximum de cases parcourues par le pion à chaque tour.  
**Coût** : Coût en or pour construire un pion de ce type.  
**PV ini (points de vie initial)** : Nombre de points de vie à la construction du pion.  
**Puiss. (puissance)** : Nombre de points de vie enlevé à la cible lors d’une attaque du pion.  
**Prod. (production)** : Quantité d'or produite par le pion (lors d'une action pour un paysan).

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- LICENSE -->
## Licence

Distribué sous la licence MIT. Voir `LICENSE.txt` pour plus d'informations.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact
Discord - ekjo
Lien : [https://github.com/jo-s-eph/La-Guerre](https://github.com/jo-s-eph/La-Guerre)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: img/1.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
