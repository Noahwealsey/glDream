#pragma once

#include "vertexBuffer.h"
#include "vertexBufferLayout.h"

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void bind()const;
	void unbind()const;

	void addBuff(const VertexBuffer &vb, const VertexBufferLayout& vbl);

private:
	
	unsigned int m_RendererID;
};