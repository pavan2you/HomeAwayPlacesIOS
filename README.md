# HomeAwayPlacesIOS

This is the generated code base, based on the HomewayPlaces Android. 

Almost 70% or even more can be machine written, It can be achieved by applying the code conversion and code generatio techniques. What developer need to focus is just the UI layer. The new Flutter framework could be a ray of home for the same. Then iOS app going to be pure by product ☺.

HomeAwayPlaces Android project, follows the clean technology agnostic way of developement approach. As a result of this, the amount of code sharing increases, almost 95% of initial commit code can be machin written, the code generation folder as of now I’ve manually fixed it. 

Please refer the conversion code log https://github.com/pavan2you/HomeAwayPlacesIOS/blob/master/homeawayplaces_ios_conversion_log.txt for the translated files.

The ios project source structure can be broadly classified into 3 sections.

CodeConversion
  - By using jVanila-iOS-Conversion script, which is wrapper around j2ObjC.

CodeGeneration
  - The remaining code DTOs / DAOs / Gateways can be generated by tool or can manually written like a template filling.

Presentation Logic
  - This is where the real implementation of View Contracts goes in and the developers would be spending majoirty of their time here. Because the other layers are either code generated or code converted.

