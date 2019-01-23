uniform sampler2D texture;
uniform vec2 pos;
void main()
{
	vec2 pixpos = (gl_FragCoord.xy-pos);
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	
	pixel.r=0.8;
	pixel.g=0.8;
	pixel.b=0.0;
	if(sin(mod(pixpos.x,20))*20 > mod(pixpos.y,20))
	{
		pixel.g=0.6;
	}
	gl_FragColor = pixel;
}