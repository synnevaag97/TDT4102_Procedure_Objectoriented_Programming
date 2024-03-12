﻿#include <chrono>
#include <thread>
#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include "utilities.h"
#include "Vehicle.h"
#include "VehicleTypes.h"
#include "Track.h"

int main() {
	auto win = std::make_unique<Fl_Double_Window>(screenWidth, screenHeight, "NASCAR");
	win->color(FL_WHITE);

	// Instansier nye objekt mellom dei to etterfølgjande linjene.
	// -----------------------------------------------------------------------------
	Track track{};
	PlayerVehicle v1{PlayerVehicle(200, 200, 0, track)};
	// -----------------------------------------------------------------------------

	win->end();
	win->show();

	auto nextDrawing = std::chrono::steady_clock::now();

	while (win->shown())
	{
		// Sov til neste teikning
		std::this_thread::sleep_until(nextDrawing);
		nextDrawing += std::chrono::microseconds(1'000'000 / 60);

		Fl::check();	// Handterar input
		Fl::redraw();	// Kallar draw
	}
}