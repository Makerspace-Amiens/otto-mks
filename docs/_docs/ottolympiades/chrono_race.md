---
layout: documentation
hide_hero: false
hero_image: otto_run.png
hero_darken: true
image: otto_run.png
component_toc: true
doc_header: true
type: ottolympiades

title: ⏱️ Chrono challenge
subtitle: Votre robot, une ligne droite, faites le meilleur temps !
description: Faites marcher votre robot le plus vite possible sur une piste contrainte par des murs verticaux !

author: Adrien BRACQ & Rémi LACOMBE
---

{% include message.html title="Attention" message="Cette page peut évoluer, pensez à la consulter régulièrement  
**V1.0 13/02/2025**" status="is-warning" dismissable="true" icon="fas fa-triangle-exclamation" %}

## Règlement

{% include step-tuto.html
greyBackground = true
title = "Déroulement de l’épreuve"
content="
- **Placement initial** :
   - Votre robot est placé derrière la ligne de départ, en **arrêt total**.
   - Une **planche est positionnée à 5 cm** devant son capteur ultrason.  

- **Début de l'épreuve** :
   - Lorsque la planche est **retirée**, le robot doit démarrer et avancer de manière **autonome**.  

- **Fin de l'épreuve** :
   - Le chrono s'arrête quand le robot franchi la ligne d'arrivée située à **80 cm** !  
   
"
image="otto_wall.png" %}

{% include step-tuto.html
greyBackground = true
title = "Conditions et contraintes"
content="
- Le robot est **autonome**, aucun contrôle à distance n’est autorisé.
- Le robot ne doit **pas bouger** avant le retrait de la planche.
- Si le robot s’arrête avant la ligne, l’essai est annulé.
- Aucun obstacle ne sera placé sur la piste, mais les irrégularités du sol peuvent influencer la course.
- Chaque équipe dispose d'autant d'essai que souhaité (dans la limite de disponibilité des pistes), seul le **meilleur temps** sera retenu."
image="otto_wake.png" %}

{% include step-tuto.html
greyBackground = true
title = "Finale et classement"
content="
En fonction du **nombre de participants**, un nombre variable de robots sera qualifié pour la phase finale :
- **2, 4, 8 ou plus** des meilleurs robots seront sélectionnés.
- Les phases finales se dérouleront en **duels sur des pistes parallèles**.
- Le premier à franchir la ligne d’arrivée remporte son duel et avance au tour suivant.
- Si seulement **deux robots** sont qualifiés, une **finale directe** aura lieu.
- En cas de nombre impair, des repêchages ou des tours préliminaires pourront être organisés.

🏆 **Le vainqueur sera l’équipe qui remportera la finale en un temps record !**"
image="otto_winner.png" %}

{% include step-tuto.html
greyBackground = true
title = "Elements de jeu"
content="**A venir**
"
image="otto_run.png" %}

## Autres épreuves

{%
  include card_collections.html
  description="Testez votre robot sur tout les terrains !"
  type="ottolympiades"
%}
