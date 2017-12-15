#include "TColor.h"
#include "helper.h"

void helper() {
	// Initialize color palette for aesthetic plots
	for (int i=0; i<CI_N; ++i) {
		ci[i] = 1789 + i;
	}
	new TColor(ci[CI_BACKGROUND], 250. / 255., 250. / 255, 250. / 255.);
	new TColor(ci[CI_E], 96. / 255., 149. / 255., 201. / 255);
	new TColor(ci[CI_MU], 205. / 255., 102. / 255., 95. / 255.);
	new TColor(ci[CI_TAU], 170. / 255., 196. / 255., 108. / 255);
	new TColor(ci[CI_NH], 50. / 255., 142. / 255., 237. / 255.);
	new TColor(ci[CI_IH], 239. / 255., 83. / 255., 138. / 255.);
	new TColor(ci[CI_1], 87. / 255., 236. / 255., 52. / 255.);
	new TColor(ci[CI_2], 35. / 255., 100. / 255., 231. / 255.);
	new TColor(ci[CI_3], 153. / 255., 89. / 255., 248. / 255.);
}
