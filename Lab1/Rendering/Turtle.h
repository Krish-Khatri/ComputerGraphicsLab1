#ifndef TURTLE_H
#define TURTLE_H

#include <iostream> 
#include <vector> 
#include <cmath> 

#define M_PI 3.14159265359

using namespace std;

namespace Turtle {

	class Pt {
	public:
		Pt() { x = 0; y = 0; }
		double x, y;
	};

	class Color {
	public:
		Color() { r = 1; g = 1; b = 1; }
		double r, g, b;
	};

	class Line {
	public:
		Line() { width = 1; }
		Pt a, b;
		Color c;
		double width;
	};

	class TurtleState {
	public:
		TurtleState() { dir = 0; }
		Pt p;
		double dir; // angle in radians
	};

	// keeps the turtle and a history of its trails 
	class TurtleMachine {
	protected:
		TurtleState _turtle;
		vector<Line> _trails;
		Color _color;
		double _width;
		double _scale;
	public:
		TurtleMachine() { reset(); }

		vector<Line>* getLines() { return &_trails; }

		void reset() {
			// fill this in
			_turtle = TurtleState();
			_trails.clear();
			_color = Color();
			_width = 1;
			_scale = 1;

		}

		void forward(double step) {
			// fill this in

			double dx = cos(_turtle.dir) * step;
			double dy = sin(_turtle.dir) * step;

			Line draw;
			draw.c = _color;
			draw.width = _width;

			draw.a.x = _turtle.p.x;
			draw.a.y = _turtle.p.y;

			_turtle.p.x += dx * _scale;
			_turtle.p.y += dy * _scale;

			draw.b.x = _turtle.p.x;
			draw.b.y = _turtle.p.y;

			_trails.push_back(draw);
		}

		void move(double step) {
			// fill this in
			double dx = cos(_turtle.dir) * step;
			double dy = sin(_turtle.dir) * step;

			_turtle.p.x += dx * _scale;
			_turtle.p.y += dy * _scale;
		}

		void turn(double ang) {
			// fill this in

			//double u = cos(_turtle.dir);
			//double v = sin(_turtle.dir);

			//double newU = u * cos(ang) - v * sin(ang);
			//double newV = u * sin(ang) + v * cos(ang);

			_turtle.dir += ang;

		}

		void resize(double s) {
			// fill this in
			_scale *= s;

		}

		void color(double r, double g, double b) {
			// fill this in
			_color.r = r;
			_color.g = g;
			_color.b = b;
		}

		void lineSize(double size) {
			// fill this in
			_width = size;
		}

		Pt pos() { return _turtle.p; }
	};

}
#endif