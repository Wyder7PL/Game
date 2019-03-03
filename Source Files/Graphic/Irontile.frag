uniform sampler2D texture;
uniform vec2 pos;
void main()
{
	vec2 pixpos = (gl_FragCoord.xy-pos);
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	
	pixel.r=0.8;
	pixel.g=0.3;
	pixel.b=0.0;
	if(mod(pixpos.x-175-pixpos.y,20) > 10 && mod(pixpos.x-175-pixpos.y,20) < 30)
	{
		if(mod(pixpos.x-175-pixpos.y,20) > 13 && mod(pixpos.x-175-pixpos.y,20) < 27)
		{pixel.r=0.6;
			pixel.g=0.25;}
		else
		{pixel.r=0.7;
		pixel.g=0.2;}
	}
	gl_FragColor = pixel;
}