---
layout: documentation
hide_hero: false
hero_image: onshapeLogo.png
hero_darken: true
image: onshapeLogo.png
component_toc: true
doc_header: true
type: tuto

title: 03 - Modifiez, exportez et imprimez Otto !
subtitle: Exportez et imprimez les pièces d'Otto
description: Cette page détaille les différentes étapes pour exporter une pièce depuis Onshape et l'imprimer

time: 1
difficulty: 1

author: Adrien BRACQ & Rémi LACOMBE

---

Maintenant que vous avez dupliqué le fichier OTTO-MKS, vous devez exporter et imprimer les pièces suivantes dans les couleurs de votre choix :

{% include step-tuto.html 
greyBackground = false
image = "Head.png"
title="1x Head"
content="" %}

{% include step-tuto.html 
greyBackground = false
image = "Body.png"
title="1x Body"
content="" %}

{% include step-tuto.html 
greyBackground = false
image = "Leg.png"
title="2x Leg"
content="" %}

{% include step-tuto.html 
greyBackground = false
image = "Feet.png"
title="1x Left_Foot & 1x Right_Foot"
content="" %}

## Exporter une pièce depuis Onshape

Sélectionnez d'abord **l'onglet** contenant la pièce à exporter. Nous prendrons comme exemple la pièce **Head**.

{% include step-tuto.html 
greyBackground = false
image = "viewport.png"
title="Sélectionnez la pièce"
content="" %}

{% include step-tuto.html 
greyBackground = false
image = "right_click.png"
title="Cliquez droit sur la pièce"
content="" %}

{% include step-tuto.html 
greyBackground = false
image = "Export.png"
title="Cliquez sur exporter et sélectionnez le format .STEP ou .3MF"
content="" %}

{% include message.html 
title="Information" 
message="Le format **.STEP** est recommandé car il offre davantage de détails et permet d'exporter un assemblage contenant plusieurs pièces distinctes" 
status="is-info" 
dismissable="true" 
icon="fas fa-exclamation" %}

{% include step-tuto.html 
greyBackground = false
image = "printerlab.png"
title="Impression"
content="Copiez le fichier téléchargé sur une **clé USB**, rendez-vous au **PrinterLab** et suivez [ce tutoriel](https://makerspace-amiens.fr/fab-additive/docs/tutorials/imprimer-une-piece/)" %}

---

{%
  include card_collections.html
  title="Pour aller plus loin"
  description="Trouvez d'autres tutoriels en lien avec le projet"
  type="tuto"
%}