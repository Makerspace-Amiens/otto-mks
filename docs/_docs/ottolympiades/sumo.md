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

todo: 10

author: Adrien BRACQ & Rémi LACOMBE
---
{% include message.html title="Attention" message="Cette page peut évoluer, pensez à la consulter régulièrement  
**V1.0 20/02/2025**" status="is-warning" dismissable="true" icon="fas fa-triangle-exclamation" %}

## Règlement

{% include step-tuto.html
greyBackground = true
title = "Déroulement de l’épreuve"
content="
- **Placement initial** :  
   - Les robots sont disposés **face à face** sur un **disque surélevé de 45 cm de diamètre**.
   - Ils sont placés à **20 cm l’un de l’autre** dans une **zone de départ rectangulaire**.
- **Début du combat** :  
   - Une **planche est placée** entre les deux robots pour bloquer leurs capteurs.
   - **L’arbitre lève la planche** pour lancer l’épreuve.
   - Les robots doivent démarrer **de manière autonome**.
- **Objectif** :  
   - Chaque robot doit tenter de **pousser l’adversaire hors de l’arène**.
   - Lorsqu’un robot sort, il **tombe de la plateforme**, signifiant sa défaite.
- **Fin du match** :  
   - Le robot restant sur l’arène est déclaré **vainqueur**.
   - Si les deux robots tombent en même temps, un **rematch** peut être décidé par l’arbitre."
image="otto_sumo_start.png" %}

{% include step-tuto.html
greyBackground = true
title = "Conditions et contraintes"
content="
- Le robot est **autonome** aucun contrôle à distance n’est autorisé.
- **Pas de coups violents** : les robots doivent pousser, pas endommager le robot adverse.
- **Aucun élément détachable** : les robots ne doivent pas perdre de pièces pendant le combat."
image="otto_sumo_rules.png" %}

{% include step-tuto.html
greyBackground = true
title = "Finale et classement"
content="
Les combats suivent un format **à élimination directe** :  
- Les **meilleurs robots** avancent aux tours suivants jusqu’à la finale.
- En cas de match nul répété, l’arbitre peut proposer une **modification des règles** (zone réduite, timer...).
- 🏆 **Le champion sera le dernier robot encore debout !**"
image="otto_sumo_podium.png" %}

{% include step-tuto.html
greyBackground = true
title = "Éléments de jeu"
content=""
image="otto_sumo_arena.png" %}

{%
  include card_collections.html
  description="Autres épreuves"
  type="ottolympiades"
%}