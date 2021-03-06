#include "numath.h"

// delta m32^2 (eV^2)
const double dm2 = 2.56e-3;
// mixing = sin^2(2 * theta23) (delta m^2 < 0)
const double mixing = 0.710;
 
// transition probability
double Pt(double x, double mix, double dm2) {
	return sinsq(2. * mix) * sinsq(1.27 * dm2 * x);
}


void twonu() {
	//gStyle->SetTitleSize(28);
	//gStyle->SetLabelFont(43);
	gStyle->SetLabelSize(0.037);
	//gStyle->SetTitleFont(43);
	gStyle->SetTitleSize(0.045);
	gStyle->SetTitleYSize(0.045);
	//gStyle->SetTitleYSize(12);

	TCanvas* canvas = new TCanvas("c1", "NuOsc2");
	TF1* f1 = new TF1("f1", "Pt(x, [0], [1])", 0., 2000.);
	TF1* f2 = new TF1("f2", "1.0 - Pt(x, [0], [1])", 0., 2000.);

	f1->SetParameter(0, mixing);
	f2->SetParameter(0, mixing);
	f1->SetParameter(1, dm2);
	f2->SetParameter(1, dm2);



	f2->SetNpx(10000);
	f1->SetNpx(10000);
	f2->SetTitle("#nu_{#mu} survival");
	f1->SetTitle("#nu_{#tau} appearance");
	f2->SetMaximum(1.0);
	f2->SetMinimum(0.0);
	canvas->SetFillColor(ci[CI_BACKGROUND]);

	f1->SetLineColor(ci[CI_3]);
	f2->SetLineColor(ci[CI_1]);
	f1->SetLineWidth(3);
	f2->SetLineWidth(3);
	f2->GetXaxis()->SetTitle("L/E (km/GeV)");
	f2->GetYaxis()->SetTitle("P(#nu_{#mu} #rightarrow #nu_{#tau})");
	f2->Draw();
	f1->Draw("same");
	
	canvas->BuildLegend();
	f2->SetTitle("");
}


