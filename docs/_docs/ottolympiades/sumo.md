---
layout: documentation
hide_hero: false
hero_image: otto_sumo.png
hero_darken: true
image: otto_sumo.png
component_toc: true
doc_header: true
type: ottolympiades

title: ⚔️ Otto Sumo
subtitle: Deux robots, un duel, un seul reste debout !
description: Poussez le robot adverse en dehors de l’arène dans un combat 100% autonome ! 

author: Adrien BRACQ & Rémi LACOMBE
---
{% include message.html title="Attention" message="Cette page peut évoluer, pensez à la consulter régulièrement  
**V1.4 24/04/2025**" status="is-warning" dismissable="true" icon="fas fa-triangle-exclamation" %}

## Présentation

L’épreuve **Otto Sumo** est un combat de robots autonomes où l’objectif est de faire tomber l’adversaire **hors de l’arène**. Deux robots s’affrontent sur une **plateforme circulaire** surélevée de **45 cm de diamètre**. Le premier robot à sortir de la zone de combat perd la manche. Aucun contrôle manuel n’est autorisé, les robots doivent agir en **totale autonomie**.

## Règlement

{% include step-tuto.html
greyBackground = true
title = "Conditions et contraintes"
content="
- Le robot est **autonome** aucun contrôle à distance n’est autorisé.
- **Pas de coups violents** : les robots doivent pousser, pas endommager le robot adverse.
- **Aucun élément détachable** : les robots ne doivent pas perdre de pièces pendant le combat."
image="otto_wake.png" %}

{% include step-tuto.html
greyBackground = true
title = "Déroulement de l’épreuve"
content="
- **Placement initial** :
   - Les robots sont disposés **face à face** et éteints sur un **disque surélevé de 45 cm de diamètre**.
   - Ils sont placés à **10 cm l’un de l’autre** derrière une **ligne de départ**.
- **Début du match** :
   - Une **planche est placée** entre les deux robots pour bloquer leurs capteurs.
   - Les robots sont allumés et doivent réaliser un **shiko**, rituel de début de match sumo qui consiste à lever chaque pied en l'air et à frapper le sol avec force.
   - **L’arbitre lève la planche** pour lancer l’épreuve.
   - Les robots doivent démarrer **de manière autonome**.
- **Fin du match**
   - Chaque robot doit tenter de **pousser l’adversaire hors de l’arène**.
   - Un match peut se terminer de plusieurs manières :

   | Mode de victoire     | Description                                                                 | Points attribués |
   |----------------------|-----------------------------------------------------------------------------|------------------|
   | **Forfait**          | L’équipe adverse ne se présente pas au match                                | 1 point          |
   | **Immobilisation**   | Le robot adverse est bloqué et reste coincé contre la bordure pendant 10 s  | 2 points         |
   | **Mort-subite**      | Le robot adverse tombe de l’arène                                           | 3 points         |


   - **Durée maximale** : un match ne peut excéder **3 minute**. Si aucun robot n’est déclaré vainqueur à l’issue du temps imparti, l’arbitre décidera de l’issue : désignation d’un vainqueur, match nul ou rematch.

"
image="otto_sumo_wall.png"
image_2="otto_sumo_fall.png"%}

{% include step-tuto.html
greyBackground = true
title = "Finale et classement"
content="
Chaque équipe se verra attribuer, de façon aléatoire et selon le nombre de participants, entre trois et cinq matchs : 
- **2, 4 ou 8** des robots ayant gagné le plus de matchs seront sélectionnés.
- Les **meilleurs robots** avancent aux tours suivants jusqu’à la finale.
- En cas de match nul répété, l’arbitre peut proposer une **modification des règles** (zone réduite, timer...).  
🏆 **Le champion sera le dernier robot encore debout !**"
image="victory.png" %}

{% include step-tuto.html
greyBackground = true
title = "Éléments de jeu"
content="**A venir...**" %}

---

{% include_relative sumo/sumo_model.html %}

---

## Autres épreuves

{%
  include card_collections.html
  description="Testez votre robot sur tout les terrains !"
  type="ottolympiades"
%}
