---
layout: documentation
hide_hero: false
hero_image: otto_obstacle.png
hero_darken: true
image: otto_obstacle.png
component_toc: true
doc_header: true
type: ottolympiades

title: 🚧 Course d'obstacle
subtitle: Traversez un parcours semé d'obstacles en un temps record !
description: Pilotez votre robot à distance et traversez un parcours semé d’obstacles en un minimum de temps.
author: Adrien BRACQ & Rémi LACOMBE
---

{% include message.html title="Attention" message="Cette page peut évoluer, pensez à la consulter régulièrement  
**V1.0 27/02/2025**" status="is-warning" dismissable="true" icon="fas fa-triangle-exclamation" %}

## Présentation

L’épreuve **Course d’obstacle** teste l'habileté et la précision de contrôle des robots. Chaque équipe doit guider son robot à travers un **parcours semé d’obstacles**, en **mode télécommandé**, et franchir la ligne d’arrivée **le plus rapidement possible**. Plusieurs **chemins** sont disponibles, chacun avec ses propres défis, rendant le choix stratégique important.

## Règlement

{% include step-tuto.html
greyBackground = true
title = "Conditions et contraintes"
content="
- L’épreuve se joue en **mode télécommandé**.
- Chaque équipe dispose d'autant d'essai que souhaité (dans la limite de disponibilité des pistes), seul le **meilleur temps** sera retenu.
- Le robot ne doit **pas bouger avant le signal** de départ de l'arbitre.
- En cas de **blocage sur un obstacle**, le robot est repositionné avant l'obstacle.
- Au bout de **trois blocages** ou si l'essai dure plus de **3 min** il est annulé.
"
image="otto_obstacle_rules.png" %}

{% include step-tuto.html
greyBackground = true
title = "Déroulement de l’épreuve"
content="
- **Placement initial** :
  - Le robot est placé derrière la ligne de départ.
- **Début du match** :
  - L’arbitre donne le signal de départ, le robot peu commencer son essai.
  - Plusieurs chemins sont possibles, chacun présentant des défis différents.
- **Fin du match** :
  - Le chronomètre s’arrête lorsque le robot **franchit la ligne d’arrivée**.
"
image="otto_obstacle_start.png"
image_2="otto_obstacle_finish.png" %}

{% include step-tuto.html
greyBackground = true
title = "Classement"
content="
🏆 **L'équipe gagnante est celle ayant réalisée le meilleur temps.**
"
image="victory.png" %}

{% include step-tuto.html
greyBackground = true
title = "Éléments de jeu"
content="**À venir...**" %}

## Autres épreuves

{%
  include card_collections.html
  description="Testez votre robot sur tous les terrains !"
  type="ottolympiades"
%}
