---
layout: multiple
title: About
---

<span class="toc">
Contents  
1. [Introduction / PAGE](#page)  
2. [Project Details](#details)  
3. [Results](#results)  
4. [Conclusions](#conclusions)  
5. [Team](#team)
</span>

# Summary

Crash and Burn is a competitive tower defence game:

* A player wins by sending units across their opponent's grid to the goal
* The player and the opponent each have a grid that they are defending by
  placing towers on it
* Towers create a longer path for and destroy units

<a name="page"></a>
# Introduction / PAGE

The artificial intelligence aspect of this game can be split up into 3 agents:

Tower: A tower is used to block units' paths and make them find a different
route to the goal. It can also shoot projectiles at a unit. If a unit's path is
blocked by towers, it will proceed to attack it.

* Percepts: in range units, surrounding towers, attacking units
* Actions: select target, shoot
* Goals: let the minimum number of units past it, do not get destroyed
* Environment: grid of game containing tower/unit/empty tiles, path of units,
  amount of units

Unit: A unit tries to traverse the grid of towers in order to make it to the
goal. They determine a path through the towers based on distance, probability of
survival, control flow, etc. If no path is available, they proceed to create a
path by attacking and destroying towers.

* Percepts: tower layout, other units' paths, tower strength
* Actions: choose direction, move toward goal, attack
* Goals: reach the goal by traversing the grid of towers, do not get destroyed
* Environment: grid of game containing tower/unit/empty tiles, addition of
  towers at any given time

Opponent: The opponent is the AI that the player plays the game against. It is
responsible for managing its resources, used to create towers and units. It lays
down towers to block the players units' path to the goal, while creating units
to traverse the player's own tower grid.

* Percepts: player's tower layout, player's units, resources count
* Actions: create unit, place tower, upgrade tower
* Goals: prevent player's units from traversing its grid, get required number of
  units through player's grid before player
* Environment: player's tower layout, path of player's units, amount of player's units

<a name="details"></a>
# Project Details

* Units: A* search to determine most efficient path, with adjusted heuristic to
  determine a safe path
* Towers: shoot closest unit until out of range or dead
* Opponent: builds towers on a pre-built path, sends units in groups to ensure
  some get through, use heuristics to determine whether to send units or place
  towers with resources

![flowchart]({{site.url}}/media/images/flowchart.png)

<a name="results"></a>
# Results

![success!]({{site.url}}/media/images/success.png)

<a name="conclusions"></a>
# Conclusions

* Computing search paths for a dynamic real-time environment is slow!
* Determining a build path for towers that makes sense takes a lot of effort.
* Main improvements that can be made:
	- Efficiency
	- Opponent heuristics refined

<a name="team"></a>
# Team

<span class="bio">
![Tyler Casella]({{site.url}}/media/images/tyler.png)
**Tyler Casella** is a 3rd year computer scientist at Cal Poly. His favorite
graphic framework to work with is XNA, although OpenGL has been growing on him.
Tyler also enjoys traveling through time to help old people of the past cross
the street.
</span>

<span class="bio">
![Andy Gonzalez]({{site.url}}/media/images/unknown.jpg)
**Andy Gonzalez** rat volutpat. Aenean eget felis mi, ut auctor mi. Quisque
fringilla diam nec enim ultricies volutpat. Cras sagittis, arcu at euismod
imperdiet, neque nisi laoreet turpis, ut tristique tellus nulla at quam. Donec
ac mauris massa.
</span>

<span class="bio">
![Ken Hung]({{site.url}}/media/images/ken.png)
**Ken Hung** is a Computer Science student at Cal Poly. He has done extensive
work with the models, particles, and animations for Crash and Burn.
</span>

<span class="bio">
![Jim Langloid]({{site.url}}/media/images/unknown.jpg)
**Jim Langloid** iaculis purus dui, et tempor sapien. Morbi ut libero ligula, eu
pellentesque sem. In quis adipiscing velit. Donec id libero vitae massa pulvinar
pulvinar ut ornare elit.
</span>

<span class="bio">
![James Pearson]({{site.url}}/media/images/pearson.jpg)
**James Pearson** is a scripting language junkie utterly in love with Python and
Ruby. Since there is currently no need for those in Crash and Burn, he works on
the AI opponent. James is also the creator and maintainer of the website.
</span>

<span class="bio">
![Josh Robinson]({{site.url}}/media/images/robinson.jpg)
**Josh Robinson** is a 3rd year Computer Science major at Cal Poly. He is graduating
in December 2010. He likes to describe himself in 3rd person because it makes
him sound cool.
</span>
