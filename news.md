---
layout: multiple
title: News
---

{% for page in site.posts %}
<div style="margin-bottom: .5em;">
	<div class="date">
		{{ page.date | date: "%Y-%m-%d" }}
	</div>
	<a href="{{site.url}}{{ page.url }}">{{ page.title }}</a>
</div>
{% endfor %}
