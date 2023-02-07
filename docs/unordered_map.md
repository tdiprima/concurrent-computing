### Bradley Lowekamp

<p>Hello,</p>

<p>Using TR1 features can be really tricky across platforms. You have a couple things to look out for:</p>

<ul>
<li>Is C++11 being used? ( using the tr1 spec or the C++11 spec? )</li>
<li>the location of the header ( some require the tr1 subdirectory ).</li>
<li>Is the header even available?</li>
</ul>

<p>Specifically, with OS X and clang the behavior is dependent on if libstdc++ or libc++, this header may not even be available with out C++11.</p>

<p>In SimpleITK I use this same header, I wrote a little wrapper which may be useful: </p>

<aside class="onebox githubblob">
  <header class="source">
    <a href="https://github.com/SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h" rel="nofollow noopener">github.com<span class="badge badge-notification clicks" title="1 click">1</span></a>
  </header>
  <article class="onebox-body">
    <h4><a href="https://github.com/SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h" rel="nofollow noopener">SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h</a></h4>
<pre><code class="lang-h hljs cpp"><span class="hljs-comment">/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/</span>
<span class="hljs-meta">#<span class="hljs-meta-keyword">ifndef</span> sitk_nsstd_unordered_map_h</span>
<span class="hljs-meta">#<span class="hljs-meta-keyword">define</span> sitk_nsstd_unordered_map_h</span>

</code></pre>

  This file has been truncated. <a href="https://github.com/SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h" rel="nofollow noopener">show original</a>

  </article>
</aside>


<p>It is based on a couple try compiles.</p>

<p>HTH,<br>Brad</p></div>

<hr>
### Andras Lasso

The officially supported compiler on Windows is **VS2013**. You can download it for free (the free **Community edition** is functionally the same as the professional editions).

Probably the best is to follow the official **documentation**:

> Visual Studio 2013 [unordered_map Class](https://msdn.microsoft.com/en-us/library/bb982522(v=vs.120).aspx)

It is [specified there](https://msdn.microsoft.com/en-us/library/bb982522(v=vs.120).aspx#Anchor_3) what **header** to include and what **namespace** the class is in.

<hr>

### Greg Sharp

If you don't have Windows, I recommend the [virtual machine](https://developer.microsoft.com/en-us/microsoft-edge/tools/vms/1) provided by Microsoft.

<hr>

### Me:

Cool.  Thank you very much! :)

I'll use that in our next release.

What I ended up [doing](https://github.com/SBU-BMI/SlicerPathology/blob/cdba3a3fa218d587e782cad5430b581d554ff613/QuickTCGA/Logic/NucleusSeg_Yi/ConnComponents.h#L13-L19) in the meantime is - I'm checking existence of header using the [Internal version numbering](https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B):

>     values of _MSC_VER for various versions of the Visual C++ compiler:
>     MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)


<hr>

**Read: [cplusplus.com/unordered_map](http://www.cplusplus.com/reference/unordered_map/unordered_map/at/)**

**MSVC**: Microsoft Visual C++

[Slicer Forum](https://discourse.slicer.org/t/solved-windows-build-unordered-map/174)
