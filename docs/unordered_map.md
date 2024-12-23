## Paraphrased discussions

### Bradley Lowekamp

Greetings!

Deploying TR1 features across different platforms can prove quite challenging. There are a few aspects to be mindful of:

- The application of C++11: This could involve using the tr1 spec or the C++11 spec.
- The location of the header: Some may require the tr1 subdirectory.
- Availability of the header.

Particularly, when using OS X and clang, the behavior hinges on whether libstdc++ or libc++ are used, and the header may not be provided without C++11.

I have utilized the same header in the SimpleITK. I suggest a handy wrapper I built, which you could find useful:

[View Code on GitHub](https://github.com/SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h)

Its design is based on a few compiled trials.

Hope this helps,   
Brad.

---

### Andras Lasso

The officially endorsed compiler on Windows is the **VS2013**. It is freely downloadable, and the functionality of the free **Community edition** mirrors that of the professional editions.

You'll find it best to follow the guidance of the official **documentation**:

- [Visual Studio 2013 Unordered_Map Class](https://msdn.microsoft.com/en-us/library/bb982522(v=vs.120).aspx)

It provides the specific instructions on the **header** to be included and the **namespace** for the class.

---

### Greg Sharp

For those without a Windows operating system, I highly recommend the [virtual machine](https://developer.microsoft.com/en-us/microsoft-edge/tools/vms/1) made available by Microsoft.

---

### Attending User:

Appreciate the advice. I'll incorporate that into our upcoming release.

In the meantime, what I ended up [doing](https://github.com/SBU-BMI/SlicerPathology/blob/cdba3a3fa218d587e782cad5430b581d554ff613/QuickTCGA/Logic/NucleusSeg_Yi/ConnComponents.h#L13-L19) is verifying the availability of headers via the [Internal version numbering](https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B).

Unfamiliar with **unordered_map**? Better acquaint yourself here: [cplusplus.com/unordered_map](http://www.cplusplus.com/reference/unordered_map/unordered_map/at/).

**Microsoft Visual C++ (MSVC)**

Join the discussion on our [Slicer Forum](https://discourse.slicer.org/t/solved-windows-build-unordered-map/174).

<br>
