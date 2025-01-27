---
layout: documentation
hide_hero: false
hero_image: otto-mks.jpg
hero_darken: true
image: otto-mks.jpg
component_toc: true
doc_header: true
type: tuto

title: 06 - Démarrer avec Arduino !
subtitle: Présentation du contexte et installation des outils
description: Cette page va vous accompagner dans la découverte d'Arduino et l'installation des différents outils.

time: 1
difficulty: 1

todo: 10

author: Adrien BRACQ & Rémi LACOMBE
---

Arduino est une plateforme de prototypage électronique qui permet de développer rapidement des projets en utilisant des cartes électroniques programmables. Pour bien comprendre comment fonctionne Arduino et ses alternatives, il est important de distinguer trois éléments essentiels :

- **Le firmware :** le logiciel interne qui gère les interactions entre le matériel et le programme utilisateur.
- **Les cartes :** le matériel physique qui exécute le code.
- **L'IDE (Environnement de Développement Intégré) :** l'interface logicielle permettant d'écrire, compiler et téléverser le code vers la carte.

## Différence entre firmware, cartes et IDE

**1. Le firmware**

  Le firmware est un programme logiciel embarqué dans la carte microcontrôleur qui permet d'exécuter les instructions du code utilisateur en gérant les ressources matérielles. Dans l'écosystème Arduino, le terme "firmware" désigne le programme interne de la carte qui assure son fonctionnement de base. Les cartes Arduino sont programmées en C/C++ et utilisent des bibliothèques comme Arduino.h, qui fournissent des abstractions facilitant le contrôle du matériel. En réalité, les utilisateurs n'écrivent pas du "code Arduino" mais bien du C/C++ enrichi par ces bibliothèques. Cela permet d'interagir avec le matériel sans devoir manipuler directement les registres du microcontrôleur.

**2. Les cartes**

  Les cartes Arduino originales (comme l'UNO, MEGA, etc.) sont conçues pour fonctionner nativement avec l'IDE Arduino. Cependant, il existe des cartes compatibles, comme la XIAO, qui offrent les mêmes fonctionnalités mais avec des performances et des caractéristiques différentes (taille réduite, consommation énergétique optimisée, connectivité avancée, etc.).

  Les cartes compatibles comme la XIAO fonctionnent avec le même IDE et firmware, mais peuvent nécessiter des bibliothèques ou des pilotes spécifiques.

**3. L'IDE Arduino**

  L'IDE Arduino est un environnement logiciel permettant d'écrire et de téléverser du code sur les cartes. Il prend en charge plusieurs cartes compatibles, y compris celles qui ne sont pas fabriquées par Arduino, tant qu'elles supportent les mêmes architectures et protocoles de communication.


---

{%
  include card_collections.html
  title="Pour aller plus loin"
  description="Trouvez d'autres tutoriels en lien avec le projet"
  type="tuto"
%}