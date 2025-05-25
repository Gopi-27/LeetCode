<h2> 17 1
3561. Resulting String After Adjacent Removals</h2><hr><div><p>You are given a string <code>s</code> consisting of lowercase English letters.</p>

<p>You <strong>must</strong> repeatedly perform the following operation while the string <code>s</code> has <strong>at least</strong> two <strong>consecutive </strong>characters:</p>

<ul>
	<li>Remove the <strong>leftmost</strong> pair of <strong>adjacent</strong> characters in the string that are <strong>consecutive</strong> in the alphabet, in either order (e.g., <code>'a'</code> and <code>'b'</code>, or <code>'b'</code> and <code>'a'</code>).</li>
	<li>Shift the remaining characters to the left to fill the gap.</li>
</ul>

<p>Return the resulting string after no more operations can be performed.</p>

<p><strong>Note:</strong> Consider the alphabet as circular, thus <code>'a'</code> and <code>'z'</code> are consecutive.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abc"</span></p>

<p><strong>Output:</strong> <span class="example-io">"c"</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Remove <code>"ab"</code> from the string, leaving <code>"c"</code> as the remaining string.</li>
	<li>No further operations are possible. Thus, the resulting string after all possible removals is <code>"c"</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "adcb"</span></p>

<p><strong>Output:</strong> <span class="example-io">""</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Remove <code>"dc"</code> from the string, leaving <code>"ab"</code> as the remaining string.</li>
	<li>Remove <code>"ab"</code> from the string, leaving <code>""</code> as the remaining string.</li>
	<li>No further operations are possible. Thus, the resulting string after all possible removals is <code>""</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "zadb"</span></p>

<p><strong>Output:</strong> <span class="example-io">"db"</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Remove <code>"za"</code> from the string, leaving <code>"db"</code> as the remaining string.</li>
	<li>No further operations are possible. Thus, the resulting string after all possible removals is <code>"db"</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>