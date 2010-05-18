---
layout: multiple
title: Welcome
---

Virus-TD is a tower defense game, created for an introductory AI course and a
graphics course at Cal Poly. [read more]({{site.url}}/about.html)

{% for page in site.posts limit:3 %}
<div class="post">
	{% include post_header.html %}
	{{ page.content }}
</div>
{% endfor %}
